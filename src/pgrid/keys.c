/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:47:20 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/06 13:47:53 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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