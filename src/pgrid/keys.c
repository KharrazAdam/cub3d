/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:47:20 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/11 01:11:44 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	mini_zoom(int key, t_map *map)
{
	if (key == PLUS && map->mini_map_d < 200)
		map->mini_map_d += 10;
	if (key == MIN && map->mini_map_d >= 100)
		map->mini_map_d -= 10;
}

int red_cross(void *map)
{
	(void)map;
	exit(0);
	return (0);
}

int key_but(int key, t_map *map)
{
	if (key == RIGHT)
		map->hook_is += ARR_R;
	if (key == LEFT)
		map->hook_is += ARR_L;
	if (key == W)
		map->hook_is += UP;
	if (key == S)
		map->hook_is += DOWN;
	if (key == A)
		map->hook_is += LF;
	if (key == D)
		map->hook_is += RH;
	if (key == ESC)
		exit(0);
	if (key == MAP)
	{
		if (map->hook_is & M)
			map->hook_is += M;
		else
			map->hook_is -= M;
	}
	if (key == O)
	{
		if (map->hook_is & OPEN)
			map->hook_is += OPEN;
		else
			map->hook_is -= OPEN;
	}
	if (key == PLUS ||key == MIN)
		mini_zoom(key, map);
	return (0);
}

int	key_rel(int	key, t_map *map)
{
	if (key == RIGHT)
		map->hook_is -= ARR_R;
	if (key == LEFT)
		map->hook_is -= ARR_L;
	if (key == W)
		map->hook_is -= UP;
	if (key == S)
		map->hook_is -= DOWN;
	if (key == A)
		map->hook_is -= LF;
	if (key == D)
		map->hook_is -= RH;
	return (0);
}