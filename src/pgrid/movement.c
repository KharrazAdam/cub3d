/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:51:33 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/08 00:11:00 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	up_down(t_map *map, int dir)
{
	map->p_pos.y += (sin(map->p_pos.ang) * SPEED) * dir;
	map->p_pos.x += (cos(map->p_pos.ang) * SPEED) * dir;
}

static void	left_right(t_map *map, int dir)
{
	map->p_pos.y += (sin(map->p_pos.ang + M_PI / 2) * SPEED) * dir;
	map->p_pos.x += (cos(map->p_pos.ang + M_PI / 2) * SPEED) * dir;

}

static void	rotate_l_r(t_map *map, int dir)
{
	map->p_pos.ang += SPEED * dir;
	map->p_pos.ang = fix_ang(map->p_pos.ang);;
}

void	move(t_map *map)
{
	if (map->hook_is & UP && map->map[(int)((map->p_pos.y + (sin(map->p_pos.ang) * SPEED)))][(int)((map->p_pos.x + (cos(map->p_pos.ang) * SPEED)))] == '0')
		up_down(map, 1);
	if (map->hook_is & DOWN && map->map[(int)(map->p_pos.y - (sin(map->p_pos.ang) * SPEED))][(int)(map->p_pos.x - (cos(map->p_pos.ang) * SPEED))] == '0')
		up_down(map, -1);
	if (map->hook_is & LF && map->map[(int)(map->p_pos.y - (sin(map->p_pos.ang + M_PI / 2) * SPEED))][(int)(map->p_pos.x - (cos(map->p_pos.ang + M_PI / 2) * SPEED))] == '0')
		left_right(map, -1);
	if (map->hook_is & RH && map->map[(int)(map->p_pos.y + (sin(map->p_pos.ang + M_PI / 2) * SPEED))][(int)(map->p_pos.x + (cos(map->p_pos.ang + M_PI / 2) * SPEED))] == '0')
		left_right(map, 1);
	if (map->hook_is & ARR_L)
		rotate_l_r(map, -1);
	if (map->hook_is & ARR_R)
		rotate_l_r(map, 1);
}
