/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:52:33 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/20 00:30:38 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	print_code(int key_code, t_map *map)
{
	if (key_code == 13)
		move_player_forward(&map->p_pos);
	else if (key_code == 2)
		move_player_backward(&map->p_pos);
	else if (key_code == 124)
		rotate_player_right(&map->p_pos);
	else if (key_code == 123)
		rotate_player_left(&map->p_pos);
	printf("x -> %f , y -> %f, ang %f\n", map->p_pos.x, map->p_pos.y, map->p_pos.ang);
	return (0);
}

void	start(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.mlx, 1920, 1080, "7waaaaaa");
	mlx_hook(map->mlx.win, 2, 0, print_code, map);
	mlx_loop(map->mlx.mlx);
}