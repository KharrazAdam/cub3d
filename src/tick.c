/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:41:44 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/16 00:28:01 by akharraz         ###   ########.fr       */
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


// 	t_tuple position = initialize_tuple(10, 10, 10, 1);
// 	t_tuple velocity = initialize_tuple(0, 1, 0, 0);
    
    
// 	t_tuple gravity = initialize_tuple(0, -0.1, 0, 0);
// 	t_tuple wind = initialize_tuple(-0.1, 0, 0, 0);
	
//     projectile.position = position;
//     projectile.velocity = velocity;

//     environment.gravity = gravity;
//     environment.wind = wind;

//     while (projectile.position.y > 0)
//     {
//         print_tuple(projectile.position);
//         tick(&projectile, &environment);
//     }
// 	return (0);
// }
