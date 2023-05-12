/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:04:01 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/12 17:56:25 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void DDA(int X0, int Y0, int X1, int Y1, t_data *data);

static bool	is_wall_v(t_ray ray, t_map *map, double ang)
{
	if ((ray.y) <= 0 || ray.y >= map->map_h)
		return (true);
	if (ang > M_PI / 2 && ang < (3 * M_PI) / 2)
		ray.x--;
	if (map->map[(int)ray.y][(int)ray.x] == '1')
		return (true);
	return (false);
}

static bool is_wall_h(t_ray ray, t_map *map, double ang)
{
	if (ray.x <= 0 || ray.x >= map->map_w)
		return (true);
	if (ang >= M_PI)
		ray.y--;
	if (map->map[(int)ray.y][(int)ray.x] == '1')
		return (true);
	return (false);
}

t_ray	vertical_intersection(t_map *map, double angle)
{
	t_ray ver;

	ver.inter = VERTICAL_INTER;
	ver.x = (int)map->p_pos.x;
	if (angle < M_PI / 2 || angle > (3 * M_PI) / 2)
		ver.x++;
	ver.y = map->p_pos.y + tan(angle) * (ver.x - map->p_pos.x);
	while (!is_wall_v(ver, map, angle))
	{
		if (angle < M_PI / 2 || angle > (3 * M_PI) / 2)
		{
			ver.x++;
			ver.y += tan(angle);
		}
		else
		{
			ver.x--;
			ver.y -= tan(angle);
		}
	}
	ver.angle = angle;
	ver.diatance = pyth(map->p_pos.x, map->p_pos.y, ver.x, ver.y);
	return (ver);
}

t_ray	hor_intersection(t_map *map, double angle)
{
	t_ray hor;

	hor.inter = HORIZONTAL_INTER;
	hor.y = (int)map->p_pos.y;
	if (angle < M_PI)
		hor.y++;
	hor.x = map->p_pos.x + (hor.y - map->p_pos.y) / tan(angle);
	while (!is_wall_h(hor, map, angle))
	{
		if (angle < M_PI)
		{
			hor.y++;
			hor.x += 1 / tan(angle);
		}
		else
		{
			hor.y--;
			hor.x -= 1 / tan(angle);
		}
	}
	hor.angle = angle;
	hor.diatance = pyth(map->p_pos.x, map->p_pos.y, hor.x, hor.y);
	return (hor);
}

void	cast(t_map *map, t_data *data)
{
	t_ray	ver;
	t_ray 	hor;
	double	angle;
	int		i;

	i = 0;
	angle = map->p_pos.ang - (FOV / 2);
	while (i < WIDTH)
	{
		angle = fix_ang(angle);
		ver = vertical_intersection(map, angle);
		hor = hor_intersection(map, angle);
		if (ver.diatance <= hor.diatance)
			show_wall(&ver, data, map, i);
		else
			show_wall(&hor, data, map ,i);
		i++;
		angle += FOV / WIDTH;
	}
}
