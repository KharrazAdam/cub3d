/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:15:04 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 00:38:49 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// int main(void)
// {
// 	t_vars mlx;
// 	t_point p;
// 	t_matrice rot_x;
// 	t_matrice rot_y;
// 	t_matrice rot_z;

// 	rot_x = matrice_rotat_x(M_PI / 6);
// 	rot_y = matrice_rotat_y(M_PI / 6);
// 	rot_z = matrice_rotat_z(M_PI / 6);

// 	p.tuple = tuple_initializer(150, 150, 250, 1);    
// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, 1500, 1500, "tick");

// 	int y;
// 	int col = 0xFFFF;
// 	int i = 0;
// 	while (i < 1200)
// 	{		
// 		y = 0;
// 		while (y < 5)
// 		{
// 			mlx_pixel_put(mlx.mlx, mlx.win, p.tuple.x + y + 250, p.tuple.y + y + 400, 0xFFFF);
// 			y++;
// 		}
		
// 		// y = 0;
// 		// while (y < 20)
// 		// {
// 		// 	mlx_pixel_put(mlx.mlx, mlx.win, p.tuple.x + y + 500, p.tuple.y + y + 500, 0xFFFF);
// 		// 	y++;	
// 		// }
// 		p.tuple = matrice_tuple_multiplication(rot_z, p.tuple);
// 		p.tuple = matrice_tuple_multiplication(rot_y, p.tuple);
// 		// p.tuple = matrice_tuple_multiplication(rot_x, p.tuple);
// 		printf("%f  %f\n", p.tuple.x, p.tuple.y);
// 		i++;
// 	}
// 	mlx_loop(mlx.mlx);
// 	return 0;
// }
