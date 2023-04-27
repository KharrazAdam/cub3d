/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 05:06:34 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/21 05:08:14 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

size_t	count_commas(char *tmp)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] == ',')
			j++;		
		i++;
	}
	return (j);
}

bool	get_rgb(char *str, int *f_col)
{
	(void)f_col;
	char	*tmp;
	char	**spl;

	tmp = ft_strtrim(str, " 	\n");
	if (!tmp)
		return (false);
	spl = ft_split(tmp, ',');
	if (!spl)
		return (free(tmp), false);
	if (count_commas(tmp) != 2 || count_att(spl) != 3)
		return (ft_putendl_fd("Error\nrbg atrributes number", 2), false);
	if (generate_rgb(f_col, spl) == false)
		return (free(tmp), clear(spl), false);
	return (free(tmp), clear(spl), true);
}

bool	fill_colour(char *key, char *str, t_map *map)
{
	int	len;

	len = ft_strlen(key);
	while (str[len] == ' ')
		len++;
	if (!ft_strncmp(key, "F", 2))
	{
		if (map->checker & F)
			return (ft_putendl_fd("Error\nF is duplicated", 2), free(key), false);
		else
		{
			if (get_rgb(str + len, &map->f_col) == false)
				return (free(key), false);
			map->checker |= F;
		}
	}
	else if (!ft_strncmp(key, "C", 2))
	{
		if (map->checker & C)
			return (ft_putendl_fd("Error\nC is duplicated", 2), free(key), false);
		else
		{
			if (get_rgb(str + len, &map->c_col) == false)
				return (free(key), false);
			map->checker |= C;
		}
	}
	return (free(key), true);
}
