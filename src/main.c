/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/14 16:38:57 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void    print_tuple(t_tuple sum)
{
	printf("x -> %f, y -> %f, z -> %f, w -> %f\n", sum.x, sum.y, sum.z, sum.w);
}

int main(void)
{
	t_vars		vars;
	t_colour	colour;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "My awesome work");
	
	colour.tuple = initialize_tuple(0, 0.98, 1, 0);
	rbg(&colour);
	float x = 50.457;
	int y = 50;
	
	printf("%x\n", (unsigned int)x);
	printf("%x\n", y);
	while (y < 450)
	{
		x = 49;
		while (++x != 450)
			mlx_pixel_put(vars.mlx, vars.win, x, y, colour.colour);
		y++;
	}
	mlx_loop(vars.mlx);
	return (0);
}
