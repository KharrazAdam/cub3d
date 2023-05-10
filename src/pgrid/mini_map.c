/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:55:16 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/10 15:01:23 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#define GR 12
void	draw_player(t_data *img, t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < GR / 4)
	{
		y = 0;
		while (y < GR / 4)
		{
			my_mlx_pixel_put(img, (map->p_pos.x * GR) + y , (map->p_pos.y * GR) + x, 0xffffff);
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

	colour = 0;
	x = 0;
	if (map->map[j][i] == '1')
		colour = 255;
	while (x < GR)
	{
		y = 0;
		while (y < GR)
		{
			my_mlx_pixel_put(img, i * GR + x, j * GR + y, colour);
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
