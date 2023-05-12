/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 04:38:43 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/12 17:55:28 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

size_t	count_att(char **attr)
{
	size_t	i;

	i = 0;
	while (attr[i])
		i++;
	return (i);
}

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

bool	is_valid(char c)
{
	return (is_player(c) || c == '1' || c == '0' || c == ' ' || c == '%');
}

bool	is_number(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (ft_putendl_fd("Error\nNon digit in rgb", 2), false);
		i++;
	}
	return (true);
}

void	clear_attr(t_map *map)
{
	if (map->n_textures)
		free(map->n_textures);
	if (map->s_textures)
		free(map->s_textures);
	if (map->e_textures)
		free(map->e_textures);
	if (map->w_textures)
		free(map->w_textures);
}