/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:34:11 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:45:53 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_point	ray_position(t_ray ray, float f)
{
	t_point	point;

	point.tuple = tuples_add(ray.origin.tuple, \
	tuple_scalar_multipli(ray.direction.tuple, f));
	return (point);
}
