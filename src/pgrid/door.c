/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:35:50 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/12 03:57:19 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	is_door(t_map *map, t_ray *ray)
{
	if (map->checker & V_DOOR && ray->inter == VERTICAL_INTER)
		return (true);
	if (map->checker & H_DOOR && ray->inter == HORIZONTAL_INTER)
		return (true);
	return (false);
}

bool	door_open(char c, t_map *map)
{
	return ((c == 'D' && !(map->checker & BONUS)));
}