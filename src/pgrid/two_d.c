/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:33:46 by akharraz          #+#    #+#             */
/*   Updated: 2023/04/27 20:26:42 by akharraz         ###   ########.fr       */
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

// bool	not_wall(t_map *map, int x, int y)
// {
// 	if (map->map[y][x] == '1')
// 		return (false);
// 	return (true);
// }

bool	is_wall(t_ray ray, t_map *map, bool check)
{
	// printf("is wall %d,  %d\n", (int)ray.y , (int)ray.x);
	if ((check == false && (ray.y > map->map_h || ray.y < 0))
		|| (check == true && (ray.x > map->map_w || ray.x < 0))
		|| map->map[(int)ray.y][(int)ray.x] == '1')
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
	while (!is_wall(ver, map, false))
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
	if (!(angle < M_PI / 2 || angle > (3 * M_PI) / 2))
		ver.x++;
	return (ver);
}

t_ray	hor_intersection(t_map *map, double angle)
{
	t_ray hor;

	hor.y = (int)map->p_pos.y;
	if (angle < M_PI)
		hor.y++;
	hor.x = map->p_pos.x + (hor.y - map->p_pos.y) / tan(angle);
	// while (!is_wall(hor, map, true))
	// {
	// 	if (angle < M_PI)
	// 	{
	// 		hor.y++;
	// 		hor.x += 1 / tan(angle);
	// 	}
	// 	else
	// 	{
	// 		hor.y--;
	// 		hor.x -= 1 / tan(angle);
	// 	}
	// }
	
	return (hor);
}

double	distance(double x, double y, double x1, double y1)
{
	return (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
}

void	cast(t_map *map, t_data *data)
{
	double	angle;
	angle = map->p_pos.ang - (FOV / 2);
	if (angle < 0)
		angle += 2 * M_PI;
	printf("angle: ray %f , player %f ray - player %f\n", angle, map->p_pos.ang, (map->p_pos.ang - angle) * 180 / M_PI);
	t_ray	ver = vertical_intersection(map, angle);
	t_ray hor = hor_intersection(map, angle);
	// printf("ver %f , %f\nhor %f , %f\n", ver.x, ver.y, hor.x, hor.y);
	// printf("distance %f , %f\n", distance(map->p_pos.x, map->p_pos.y, ver.x, ver.y), distance(map->p_pos.x, map->p_pos.y, hor.x, hor.y));
	if (distance(map->p_pos.x, map->p_pos.y, ver.x, ver.y) < distance(map->p_pos.x, map->p_pos.y, hor.x, hor.y))
		DDA(map->p_pos.x * FS, map->p_pos.y * FS, ver.x * FS, ver.y * FS, data);
	else
		DDA(map->p_pos.x * FS, map->p_pos.y * FS, hor.x * FS, hor.y * FS, data);
}

int draw_map(t_map *map)
{
	int i, j;
	t_data img;
	move(map);
	img.img = mlx_new_image(map->mlx.mlx, (map->map_w - 1) * FS, map->map_h * FS);
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