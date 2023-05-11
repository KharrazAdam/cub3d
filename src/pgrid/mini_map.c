/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:55:16 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/10 23:18:06 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_player(t_data *img, t_map *map)
{
	int x;
	int y;
	int	gr;

	x = 0;
	gr = map->mini_map_d / map->map_h;
	while (x < gr / 4)
	{
		y = 0;
		while (y < gr / 4)
		{
			my_mlx_pixel_put(img, (map->p_pos.x * gr) + y , (map->p_pos.y * gr) + x, 0xffffff);
			y++;
		}
		x++;
	}
}

void draw_grid(t_data *img, int i, int j, t_map *map)
{
	int colour;
	int	x;
	int	y;
	int	gr;

	colour = 0;
	x = 0;
	if (map->map[j][i] == '1')
		colour = 255;
	gr = map->mini_map_d / map->map_h;
	while (x < gr)
	{
		y = 0;
		while (y < gr)
		{
			my_mlx_pixel_put(img, i * gr + x, j * gr + y, colour);
			y++;
		}
		x++;
	}
}

void	draw_mini_map(t_data *img, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->map_w - 1)
	{
		j = 0;
		while (j < map->map_h)
		{
			draw_grid(img, i, j, map);
			j++;
		}
		i++;
	}
	draw_player(img, map);
}
