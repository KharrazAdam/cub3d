/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:33:46 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/12 01:52:24 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

int display_game(t_map *map)
{
	t_data img;

	move(map);
	img.img = mlx_new_image(map->mlx.mlx, WIDTH, HIGHT);
	img.addr = (unsigned int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
										&img.endian);
	cast(map, &img);
	if (map->hook_is & M)
		draw_mini_map(&img, map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, img.img, 0, 0);
	mlx_destroy_image(map->mlx.mlx, img.img);
	return (0);
}
