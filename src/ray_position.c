/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:34:11 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/28 21:30:11 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_point ray_position(t_ray ray, float f)
{
    t_point point;
    
    point.tuple = tuples_add(ray.origin.tuple, tuple_scalar_multipli(ray.direction.tuple, f));
    return (point);
}
