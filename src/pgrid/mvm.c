/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:51:33 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/06 17:39:22 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move(t_map *map)
{
	if (map->hook_is & UP && map->map[(int)((map->p_pos.y + (sin(map->p_pos.ang) * SPEED) + 0.1))][(int)((map->p_pos.x + (cos(map->p_pos.ang) * SPEED) + 0.1))] == '0')
	{
		map->p_pos.y += (sin(map->p_pos.ang) * SPEED);
		map->p_pos.x += (cos(map->p_pos.ang) * SPEED);
	}
	if (map->hook_is & DOWN && map->map[(int)(map->p_pos.y - (sin(map->p_pos.ang) * SPEED) + 0.1)][(int)(map->p_pos.x - (cos(map->p_pos.ang) * SPEED) + 0.1)] == '0')
	{
		map->p_pos.y -= (sin(map->p_pos.ang) * SPEED);
		map->p_pos.x -= (cos(map->p_pos.ang) * SPEED);
	}
	if (map->hook_is & LF && map->map[(int)(map->p_pos.y - (sin(map->p_pos.ang + M_PI / 2) * SPEED) + 0.1)][(int)(map->p_pos.x - (cos(map->p_pos.ang + M_PI / 2) * SPEED) + 0.1)] == '0')
	{
		map->p_pos.y -= (sin(map->p_pos.ang + M_PI / 2) * SPEED);
		map->p_pos.x -= (cos(map->p_pos.ang + M_PI / 2) * SPEED);
	}
	if (map->hook_is & RH && map->map[(int)(map->p_pos.y + (sin(map->p_pos.ang + M_PI / 2) * SPEED) + 0.1)][(int)(map->p_pos.x + (cos(map->p_pos.ang + M_PI / 2) * SPEED) + 0.1)] == '0')
	{
		map->p_pos.y += (sin(map->p_pos.ang + M_PI / 2) * SPEED);
		map->p_pos.x += (cos(map->p_pos.ang + M_PI / 2) * SPEED);
	}
	if (map->hook_is & ARR_L)
	{
		map->p_pos.ang -= SPEED;
		if (map->p_pos.ang < 0)
			map->p_pos.ang += 2.0 * M_PI;
	}
	if (map->hook_is & ARR_R)
		map->p_pos.ang += SPEED;
	if (map->p_pos.ang > 2.0 * M_PI)
		map->p_pos.ang -= 2.0 * M_PI;
}
