/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 04:21:43 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/12 02:55:53 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static char	*skip_empty_lines(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (str[0] != '\n')
		{
			return (str);
		}
		free(str);
		str = get_next_line(fd);
	}
	return (NULL);
}

bool	fill_map_list(t_list **list, int fd, int *map_w)
{
	char	*str;
	int		len;

	str = skip_empty_lines(fd);
	if (str == NULL)
		return (ft_putendl_fd("Error\nNo mini map", 2), free(str), false);
	*map_w = ft_strlen(str);
	while (str)
	{
		len = ft_strlen(str);
		if (len > *map_w)
			*map_w = len;
		if (!str[0] || str[0] == '\n')
			return (ft_putendl_fd("Error\nempty line in mini map", 2), free(str), false);
		ft_lstadd_back(list, ft_lstnew(ft_strdup(str)));
		free(str);
		str = get_next_line(fd);
	}
	return (true);
}

bool	fill_map_array(t_list **list, t_map *map)
{
	t_list *tmp;
	int		i;
	int		len;
	char	*content;

	i = 0;
	tmp = *list;
	map->map_h = ft_lstsize(tmp);
	map->map = ft_calloc(sizeof(char *), map->map_h + 1);
	if (!map->map)
		return (ft_putendl_fd("Error\nft_calloc", 2), false);
	while (tmp)
	{
		content = ft_calloc(sizeof(char), map->map_w + 1);
		if (!content)
			return (ft_putendl_fd("Error\nft_calloc", 2), clear(map->map), false);
		len = ft_strlen((char *)tmp->content);
		ft_strlcpy(content, (char *)tmp->content, len + 1);
		map->map[i] = ft_strtrim(content, "\n");
		if (!map->map[i])
			return (ft_putendl_fd("Error\nft_calloc", 2), clear(map->map), free(content), false);
		free(content);
		tmp = tmp->next;
		i++;
	}
	map->map[i] = 0;
	return (true);
}

char	**creat_tmp_map(t_map *map)
{
	char **ret;
	int	i;
	int	len;

	i = 0;
	ret = ft_calloc(sizeof(char *), map->map_h + 1);
	if (!ret)
		return (ft_putendl_fd("Error\ncalloc failed", 2), NULL);
	while (map->map[i])
	{
		ret[i] = ft_calloc(sizeof(char *), map->map_w + 1);
		if (!ret[i])
			return (ft_putendl_fd("Error\ncalloc failed", 2), clear(ret), NULL);
		len = ft_strlen(map->map[i]);
		ft_strlcpy(ret[i], map->map[i], len + 1);
		while (len + 1 < map->map_w)
		{
			ret[i][len] = '%';
			len++;
		}
		i++;
	}
	ret[i] = 0;
	return (ret);
}

void	rp_void(char **tmp, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == ' ' || tmp[i][j] == '%')
				map->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

bool	map_valid(t_map *map)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	map->p_pos.ang = -1;
	tmp = creat_tmp_map(map);
	if (!tmp || !map->map[0][0])
		return (false);
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (is_valid(tmp[i][j]) == false)
					return (ft_putendl_fd("Error\nUnknown character", 2), clear(tmp), false);
			if (is_player(tmp[i][j]) || tmp[i][j] == '0')
				if (sur_check(i, j, tmp) == false)
					return (clear(tmp), false);
			if (tmp[i][j] == 'D')
				map->checker += BONUS;
			if (is_player(tmp[i][j]) == true)
			{
				if (map->p_pos.ang != -1)
					return (ft_putendl_fd("Error\nduplicated player", 2), clear(tmp), false);
				if (tmp[i][j] == 'N')
					map->p_pos.ang = M_PI / 2;
				else if (tmp[i][j] == 'S')
					map->p_pos.ang = 3 * M_PI / 2;
				else if (tmp[i][j] == 'W')
					map->p_pos.ang = M_PI;
				else if (tmp[i][j] == 'E')
					map->p_pos.ang = 0;
				map->map[i][j] = '0';
				map->p_pos.x = j + 0.5;
				map->p_pos.y = i + 0.5;
			}
			j++;
		}
		i++;
	}
	if (map->p_pos.ang == -1)
		return (ft_putendl_fd("Error\nNo player", 2), false);
	rp_void(tmp, map);
	return (clear(tmp), true);
}

bool	check_map(t_map *map, int fd)
{
	t_list	**list;

	list = ft_calloc(sizeof(t_list *), 1);
	if (!list)
		return (false);
	if (fill_map_list(list, fd, &map->map_w) == false)
		return (ft_lstclear(list, free), false);
	if (fill_map_array(list, map) == false)
		return (ft_lstclear(list, free), false);
	if (map_valid(map) == false)
		return (ft_lstclear(list, free),false);
	return (ft_lstclear(list, free), true);
}
