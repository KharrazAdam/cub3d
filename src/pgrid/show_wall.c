/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:10:24 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/12 17:56:58 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	show_ceil_floor(int proj, t_data *img, t_map *map, int x)
{
	int	start;
	int	end;

	start = -1;
	end = (HIGHT - proj) / 2;
	while (++start < end)
		my_mlx_pixel_put(img, x ,start, map->c_col);
	end += proj - 1;
	while (++end < HIGHT)
		my_mlx_pixel_put(img, x ,end, map->f_col);
}

void	paint_wall(t_data wall, t_data *img, t_ray *ray, int x)
{
	int				start;
	int				end;
	t_coordinates	tex;
	int				i;

	i = 0;
	if (ray->inter == HORIZONTAL_INTER)
		tex.x = ((ray->x - (int)ray->x) * wall.w);
	else
		tex.x = ((ray->y - (int)ray->y) * wall.w);
	start = (int)((HIGHT - ray->proj) / 2);
	end = (int)(start + ray->proj);
	int save = start;
	while (start < end)
	{
		i = start - save;
		tex.y = (int)(i * wall.h / ray->proj);
		if (start >= HIGHT)
			return ;
		if (start < 0)
			start = 0;
		my_mlx_pixel_put(img, x , start, wall.addr[(int)((wall.h * tex.y) + tex.x)]);
		start++;
	}
}

void	show_wall(t_ray *ray, t_data *img, t_map *map, int x)
{
	ray->diatance *= cos((ray->angle - map->p_pos.ang));
	ray->proj = (1 * ((WIDTH / 2) / FS) / ray->diatance) * FS;
	show_ceil_floor(ray->proj, img, map, x);
	if (ray->inter && ray->angle <= M_PI)
		paint_wall(map->no, img, ray, x);
	else if (ray->inter && ray->angle > M_PI)
		paint_wall(map->so, img, ray, x);
	if (!ray->inter && (ray->angle >= M_PI_2 && ray->angle <= 3 * M_PI_2))
		paint_wall(map->we, img, ray, x);
	else if (!ray->inter && !(ray->angle >= M_PI_2 && ray->angle <= 3 * M_PI_2))
		paint_wall(map->ea, img, ray, x);
}
