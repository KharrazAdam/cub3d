/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:51:33 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/12 17:57:55 by akharraz         ###   ########.fr       */
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

void	rotate_l_r(t_map *map, int dir)
{
	map->p_pos.ang += SPEED * dir;
	map->p_pos.ang = fix_ang(map->p_pos.ang);;
}

void	move(t_map *map)
{
	int	x;
	int	y;

	if (map->hook_is & UP)
	{
		x = (int)((map->p_pos.y + (sin(map->p_pos.ang) * SPEED)));
		y = (int)((map->p_pos.x + (cos(map->p_pos.ang) * SPEED)));
		if (map->map[x][y] == '0')
			up_down(map, 1);
	}
	if (map->hook_is & DOWN)
		{
			x = (int)(map->p_pos.y - (sin(map->p_pos.ang) * SPEED));
			y = (int)(map->p_pos.x - (cos(map->p_pos.ang) * SPEED));
			if (map->map[x][y] == '0')
				up_down(map, -1);
		}
	if (map->hook_is & LF)
		{
			x = (int)(map->p_pos.y - (sin(map->p_pos.ang + M_PI / 2) * SPEED));
			y = (int)(map->p_pos.x - (cos(map->p_pos.ang + M_PI / 2) * SPEED));
			if (map->map[x][y] == '0')
				left_right(map, -1);
		}
	if (map->hook_is & RH)
		{
			x = (int)(map->p_pos.y + (sin(map->p_pos.ang + M_PI / 2) * SPEED));
			y = (int)(map->p_pos.x + (cos(map->p_pos.ang + M_PI / 2) * SPEED));
			if (map->map[x][y] == '0')
				left_right(map, 1);
		}
	if (map->hook_is & ARR_L)
		rotate_l_r(map, -1);
	if (map->hook_is & ARR_R)
		rotate_l_r(map, 1);
}
