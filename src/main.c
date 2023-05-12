/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:42:12 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/12 18:00:00 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	fill_xpm(t_data *xpm, char *path, void *mlx)
{
	xpm->img = mlx_xpm_file_to_image(mlx, path, &xpm->w, &xpm->h);
	if (!xpm->img)
		return (ft_putendl_fd("Error\nissue in .xpm file", 2), 0);
	xpm->addr = (unsigned int *)mlx_get_data_addr(xpm->img, &xpm->bits_per_pixel, &xpm->line_length, &xpm->endian);
	if (!xpm->addr)
		return (ft_putendl_fd("Error\nissue in .xpm adrr", 2), 0);
	return (1);
}

bool	xpm_convert(t_map *map)
{
	if (!fill_xpm(&map->no, map->n_textures, map->mlx.mlx))
		return (false);
	if (!fill_xpm(&map->so, map->s_textures, map->mlx.mlx))
		return (false);
	if (!fill_xpm(&map->ea, map->e_textures, map->mlx.mlx))
		return (false);
	if (!fill_xpm(&map->we, map->w_textures, map->mlx.mlx))
		return (false);
	return (true);
}

int afak(t_map *map)
{
	map->mlx.mlx = mlx_init(map);
	if (xpm_convert(map) == false)
		exit (1);
	map->mlx.win = mlx_new_window(map->mlx.mlx, WIDTH, HIGHT, "cub3D");
	if (!map->mlx.win)
		return (ft_putendl_fd("Error\nissue in mlx_new_window", 2), 1);
	mlx_loop_hook(map->mlx.mlx, display_game, map);
	mlx_hook(map->mlx.win, 2, 0, key_but, map);
	mlx_hook(map->mlx.win, 3, 2, key_rel, map);
	mlx_hook(map->mlx.win, 17, 1L, red_cross, map);
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
		exit (1);
	if (afak(&map) == 1)
		exit (1);
	return (0);
}
