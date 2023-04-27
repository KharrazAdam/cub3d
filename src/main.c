/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:42:12 by akharraz          #+#    #+#             */
/*   Updated: 2023/04/27 20:14:41 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int red_cross(void *map)
{
	(void)map;
	exit(0);
	return (0);
}

int key_but(int key, t_map *map)
{
	if (key == RIGHT)
		map->hook_is += ARR_R;
	if (key == LEFT)
		map->hook_is += ARR_L;
	if (key == W)
		map->hook_is += UP;
	if (key == S)
		map->hook_is += DOWN;
	if (key == A)
		map->hook_is += LF;
	if (key == D)
		map->hook_is += RH;
	if (key == ESC)
		exit(0);
	return (0);
}

int	key_rel(int	key, t_map *map)
{
	if (key == RIGHT)
		map->hook_is -= ARR_R;
	if (key == LEFT)
		map->hook_is -= ARR_L;
	if (key == W)
		map->hook_is -= UP;
	if (key == S)
		map->hook_is -= DOWN;
	if (key == A)
		map->hook_is -= LF;
	if (key == D)
		map->hook_is -= RH;
	return (0);
}

int afak(t_map *map)
{
	t_data img;

	map->mlx.mlx = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.mlx, (map->map_w - 1) * FS, map->map_h * FS, "cub3D");
	img.img = mlx_new_image(map->mlx.mlx, (map->map_w - 1) * FS, map->map_h * FS);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	mlx_loop_hook(map->mlx.mlx, draw_map, map);
	mlx_hook(map->mlx.win, 2, 1, key_but, map);
	mlx_hook(map->mlx.win, 3, 2, key_rel, map);
	mlx_hook(map->mlx.win, 17, 0, red_cross, map);
	mlx_loop(map->mlx.mlx);
	return (1);
}

int main(int ac, char **av)
{
	t_map map;

	ft_bzero(&map, sizeof(t_map));
	if (ac != 2)
		return (ft_putendl_fd("Error\nnumber of argumants must be 2!", 2), 1);
	if (parsing(&map, av[1]) == 1)
		return (1);
	afak(&map);
	// printf("%f, %f\n", cos(2 * (M_PI / 3)), cos(4 * (M_PI / 3)));
	// printf("%f        %f\n", cos(M_PI / 12) / sin(M_PI / 12), 1 / tan(M_PI / 12));
	return (0);
}
