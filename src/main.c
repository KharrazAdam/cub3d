/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/01 21:35:32 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

int main(void)
{
	t_ray ray;
	t_sphere sphere;

	ray = ray_init(point_initializer(0, 0, 0), vetor_initializer(0, 0, 1));
	sphere.var = 1;
    ray_discriminant(&ray);
    printf("t1 == %f, t2 == %f", ray.xs.t1, ray.xs.t2);

	// tuple_print(ray_position(ray, -1).tuple);
}

// /**
//   !as
//   ?sada
//   TODO ds
//   * dfgdfs
//   // fdsfsdfs
//   //! dfgdhiofgjld
// */
