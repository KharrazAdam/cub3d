/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:15:52 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/06 14:52:01 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*get_key(char *str)
{
	int		i;
	int		err;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	err = i;
	ret = ft_calloc(i + 1, 1);
	if (!ret)
		return (NULL);
	while (str[err] && str[err] == ' ')
		err++;
	if (!str[err])
		return (ft_putendl_fd("Error\nA key doesn't have value", 2), free(ret), NULL);
	ft_strlcpy(ret, str, i + 1);
	return (ret);
}

bool	generate_rgb(int *f_col, char **spl)
{
	int	i;
	int	deg;
	int	ato;

	i = 0;
	deg = 16;
	while (spl[i])
	{
		if (is_number(spl[i]) == false)
			return (false);
		ato = ft_atoi(spl[i]);
		if (!(ato >= 0 && ato <= 255))
			return (ft_putendl_fd("Error\nOut of range 0 -> 255", 2), false);
		*f_col += ato << deg;
		i++;
		deg -= 8;
	}
	return (true);
}

bool	fill_text(char *key, char *str, t_map *map)
{
	int		len;
	char	*tmp;

	len = ft_strlen(key);
	while (str[len] == ' ')
		len++;
	tmp = ft_substr(str, len, ft_strlen(str) - len);
	if (!ft_strncmp(key, "NO", 3))
	{
		if (map->checker & NO)
			return (ft_putendl_fd("Error\nNO is duplicated", 2), free(key), false);
		else
		{
			map->checker |= NO;
			map->n_textures = ft_strtrim(tmp, " 	\n");
		}
	}
	else if (!ft_strncmp(key, "SO", 3))
	{
		if (map->checker & SO)
			return (ft_putendl_fd("Error\nSO is duplicated", 2), free(key), false);
		else
		{
			map->checker |= SO;
			map->s_textures = ft_strtrim(tmp, " 	\n");
		}
	}
	else if (!ft_strncmp(key, "EA", 3))
	{
		if (map->checker & EA)
			return (ft_putendl_fd("Error\nEA is duplicated", 2), free(key), false);
		else
		{
			map->checker |= EA;
			map->e_textures = ft_strtrim(tmp, " 	\n");
		}
	}
	else if (!ft_strncmp(key, "WE", 3))
	{
		if (map->checker & WE)
			return (ft_putendl_fd("Error\nWE is duplicated", 2), free(key), false);
		else
		{
			map->checker |= WE;
			map->w_textures = ft_strtrim(tmp, " 	\n");
		}
	}
	if (tmp)
		free(tmp);
	return (free(key), true);	
}

bool	ft_fill(char *str, t_map *map)
{
	char	*key;

	key = get_key(str);
	if (!key)
		return (NULL);
	if (!ft_strncmp(key, "NO", 3) || !ft_strncmp(key, "SO", 3) || !ft_strncmp(key, "EA", 3) || !ft_strncmp(key, "WE", 3))
		return (fill_text(key, str, map));
	else if (!ft_strncmp(key, "F", 2) || !ft_strncmp(key, "C", 2))
		return (fill_colour(key, str, map));
	return (ft_putendl_fd("Error\nKey not valid", 2), free(key), false);
}

bool	check_elements(t_map *map, int fd)
{
	int		count;
	char	*str;

	count = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (str[0] == '\n')
			;
		else
		{
			if (ft_fill(str, map) == false)
				return (free(str), clear_attr(map), false);
			count++;
			if (count == 6)
			{
				free(str);
				break ;
			}
		}
		free(str);
		str = get_next_line(fd);
	}
	return (true);
}
