/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:41:44 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/19 03:56:05 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void    tick(t_projectile* proj, t_environment* env)
{
	proj->position = tuples_add(proj->position, proj->velocity); //position ← proj.position + proj.velocity
	proj->velocity = tuples_add(tuples_add(proj->velocity, env->gravity), env->wind);
	//velocity ← proj.velocity + env.gravity + env.win
	return ;
}


// int main(void)
// {
// 	t_projectile	projectile;
// 	t_environment	environment;
//     t_canvas        can = canvas_initializer(1400, 700);
//     t_vars          vars;

// 	t_tuple position = tuple_initializer(0, 1, 0, 1);
// 	t_tuple velocity = tuple_initializer(0, 1, 0, 0);

//     velocity = nrml(velocity);
//     velocity = scalar_multipli(velocity, 11.25);
// 	t_tuple gravity = tuple_initializer(0, -0.1, 0, 0);
// 	t_tuple wind = tuple_initializer(-0.1, 0, 0, 0);
	
//     projectile.position = position;
//     projectile.velocity = velocity;

//     environment.gravity = gravity;
//     environment.wind = wind;
//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, can.width, can.height, "tick");

//     while (projectile.position.y > 0)
//     {
//         mlx_pixel_put(vars.mlx, vars.win, 1400 + projectile.position.x, 700 - projectile.position.y, 255 << 16 | 255 << 8);
//         tuple_print(projectile.position);
//         tick(&projectile, &environment);
//     }
// 	mlx_loop(vars.mlx);
// 	return (0);
// }
