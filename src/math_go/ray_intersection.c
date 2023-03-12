/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:31:47 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:45:33 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	ray_intersect(t_ray *ray)
{
	t_point	sphere_to_ray;
	float	a;
	float	b;
	float	c;

	sphere_to_ray.tuple = \
	tuples_Subtracting(ray->origin.tuple, tuple_initializer(0, 0, 0, 1));
	a = tuple_dot_product(ray->direction.tuple, ray->direction.tuple);
	b = 2 * tuple_dot_product(ray->direction.tuple, sphere_to_ray.tuple);
	c = tuple_dot_product(sphere_to_ray.tuple, sphere_to_ray.tuple) - 1;
	ray->xs.discriminant = pow(b, 2) - (4 * a * c);
	if (ray->xs.discriminant < 0)
		return (false);
	ray->xs.t1 = (-b + sqrt(ray->xs.discriminant)) / (2 * a);
	ray->xs.t2 = (-b - sqrt(ray->xs.discriminant)) / (2 * a);
	ray->xs.count = 2;
	return (true);
}
