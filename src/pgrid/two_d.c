/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:33:46 by akharraz          #+#    #+#             */
/*   Updated: 2023/04/28 17:41:14 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_player(t_data *img, t_map *map)
{
	for (int x = 0; x < 10; x++)
		my_mlx_pixel_put(img, (map->p_pos.x * FS + (cos(map->p_pos.ang)) * x), map->p_pos.y * FS + (sin(map->p_pos.ang) * x), 0x2271b3);
}

void draw_grid(t_data *img, int i, int j, t_map *map)
{
	int colour;
	int x, y;

	colour = 0x00FFFFFF;
	x = 0;
	if (map->map[j][i] == '1')
		colour = 0x00C0F000;
	while (x < FS - 1)
	{
		y = 0;
		while (y < FS - 1)
		{
			my_mlx_pixel_put(img, i * FS + x, j * FS + y, colour);
			y++;
		}
		x++;
	}
}

int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

void DDA(int X0, int Y0, int X1, int Y1, t_data *data)
{
	int dx = X1 - X0;
	int dy = Y1 - Y0;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	float X = X0;
	float Y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(data, round(X), round(Y), 0xFF0000);
		X += Xinc; // increment in x at each step
		Y += Yinc; // increment in y at each step
	}
}

bool	is_wall_v(t_ray ray, t_map *map, double ang)
{
	if ((ray.y) <= 0 || ray.y >= map->map_h)
		return (true);
	if (ang > M_PI / 2 && ang < (3 * M_PI) / 2)
		ray.x--;
	if (map->map[(int)ray.y][(int)ray.x] == '1')
		return (true);
	return (false);
}

bool is_wall_h(t_ray ray, t_map *map, double ang)
{
	if (ray.x <= 0 || ray.x >= map->map_w)
		return (true);
	if (ang >= M_PI)
		ray.y--;
	(void)ang;
	if (map->map[(int)ray.y][(int)ray.x] == '1')
		return (true);
	return (false);
}

t_ray	vertical_intersection(t_map *map, double angle)
{
	t_ray ver;

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
	return (ver);
}

t_ray	hor_intersection(t_map *map, double angle)
{
	t_ray hor;

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
	return (hor);
}

double	distance(double x, double y, double x1, double y1)
{
	return (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
}

double	normalize_angle(double angle) ///// why!!!!!!???????????????
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
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
		angle = normalize_angle(angle);
		ver = vertical_intersection(map, angle);
		hor = hor_intersection(map, angle);
		(void)hor;
		(void)ver;
		(void)data;
		if (distance(map->p_pos.x, map->p_pos.y, ver.x, ver.y) < distance(map->p_pos.x, map->p_pos.y, hor.x, hor.y))
			DDA(map->p_pos.x * FS, map->p_pos.y * FS, ver.x * FS, ver.y * FS, data);
		else
			DDA(map->p_pos.x * FS, map->p_pos.y * FS, hor.x * FS, hor.y * FS, data);
		i++;
		angle += FOV / WIDTH;
	}
}

int draw_map(t_map *map)
{
	int i, j;
	t_data img;
	move(map);
	img.img = mlx_new_image(map->mlx.mlx, WIDTH, HIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
										&img.endian);
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			draw_grid(&img, i, j, map);
			i++;
		}
		j++;
	}
	draw_player(&img, map);
	cast(map, &img);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, img.img, 0, 0);
	mlx_destroy_image(map->mlx.mlx, img.img);
	return (0);
}