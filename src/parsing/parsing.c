/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:40:28 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/10 22:30:00 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_list	**read_file(int fd)
{
	char	*line;
	t_list	**assets;
	t_list	*node;

	assets = ft_calloc(sizeof(t_list *), 1);
	if (!assets)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] && line[0] != '\n')
		{
			node = ft_lstnew(line);
			ft_lstadd_back(assets, node);
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	return (assets);
}

int	check_and_fill_ambient_light(char *attributes, t_ambient *ambient_light)
{
	char	**tmp;
	char	**tmp1;
	int		j;

	tmp = ft_split(attributes, ' ');
	j = 0;
	if (count_att(tmp) != 3)
		return (clear(tmp), 0);
	if (!check_float(tmp[1]))
		return (clear(tmp), 0);
	tmp1 = ft_split(tmp[2], ',');
	while (tmp1[j])
	{
		if (!check_float(tmp1[j]))
			return (clear(tmp), clear(tmp1), 0);
		j++;
	}
	ambient_light->ratio = ft_atof(tmp[1]);
	if (!check_rgb(tmp1))
		return (clear(tmp), clear(tmp1), 0);
	ambient_light->col = colour_initializer(ft_atoi(tmp[0]),
			ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	ambient_light->is_init = 1;
	return (clear(tmp), clear(tmp1), 1);
}

int	check_and_fill_camera(char *attributes, t_camera *camera)
{
	char	**tmp;
	char	**tmp1;
	int		j;

	tmp = ft_split(attributes, ' ');
	j = -1;
	if (count_att(tmp) != 4)
		return (clear(tmp), 0);
	if (!check_float(tmp[3]))
		return (clear(tmp), 0);
	tmp1 = ft_split(tmp[1], ',');
	while (tmp1[++j])
		if (!check_float(tmp1[j]))
			return (clear(tmp), clear(tmp1), 0);
	camera->h_fov = ft_atof(tmp[3]);
	camera->position = point_initializer(ft_atof(tmp[0]),
			ft_atof(tmp[1]), ft_atof(tmp[2]));
	clear(tmp1);
	tmp1 = ft_split(tmp[2], ',');
	camera->direction = vetor_initializer(ft_atof(tmp1[0]),
			ft_atof(tmp1[1]), ft_atof(tmp1[2]));
	camera->is_init = 1;
	return (clear(tmp), clear(tmp1), 1);
}

int	check_and_fill_light(char *attributes, t_light *light)
{
	char	**tmp;
	char	**tmp1;
	int		j;

	tmp = ft_split(attributes, ' ');
	j = -1;
	if (count_att(tmp) != 4 && !check_float(tmp[2]))
		return (clear(tmp), 0);
	tmp1 = ft_split(tmp[1], ',');
	while (tmp1[++j])
		if (!check_float(tmp1[j]))
			return (clear(tmp), clear(tmp1), 0);
	light->brightness = ft_atof(tmp[2]);
	light->position = point_initializer(ft_atof(tmp1[0]),
			ft_atof(tmp1[1]), ft_atof(tmp1[2]));
	clear(tmp1);
	tmp1 = ft_split(tmp[3], ',');
	j = 0;
	if (!check_rgb(tmp1))
		return (clear(tmp), clear(tmp1), 0);
	light->col = colour_initializer(ft_atoi(tmp[0]),
			ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	light->is_init = 1;
	return (clear(tmp), clear(tmp1), 1);
}

int	check_and_fill_lights(t_ambient *ambient_light, t_camera *camera, t_light *light, t_list **rt_file)
{
	t_list  *node;
	t_list  *tmp_node;
	char    **tmp;
	int     i;

	node = *rt_file;
	i = 0;
	while (node)
	{
		tmp = NULL;
		if (ft_strchr(node->content, 'A'))
		{
			tmp = ft_split(node->content, ' ');
			if (ft_strncmp(tmp[0], "A", 2))
				return(clear(tmp), 0);
			else
			{
				if(!check_and_fill_ambient_light(node->content, ambient_light))
					return(clear(tmp), 0);
				tmp_node = node;
				node = node->next;
				lst_pop_node(rt_file, tmp_node);
			}
			++i;
		}
		else if (ft_strchr(node->content, 'C'))
		{
			tmp = ft_split(node->content, ' ');
			if (ft_strncmp(tmp[0], "C", 2))
				return(clear(tmp), 0);
			else
			{
				if (!check_and_fill_camera(node->content, camera))
					return(clear(tmp), 0);
				tmp_node = node;
				node = node->next;
				lst_pop_node(rt_file, tmp_node);
			}
			++i;
		}
		else if (ft_strchr(node->content, 'L'))
		{
			tmp = ft_split(node->content, ' ');
			if (ft_strncmp(tmp[0], "L", 2))
				return(clear(tmp), 0);
			else
			{
				if (!check_and_fill_light(node->content, light))
					return(clear(tmp), 0);
				tmp_node = node;
				node = node->next;
				lst_pop_node(rt_file, tmp_node);
			}
			++i;
		}
		else
			node = node->next;
		if (tmp)
			clear(tmp);
	}
	return (i);
}
