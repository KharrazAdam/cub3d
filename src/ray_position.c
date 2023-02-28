/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:34:11 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/28 19:01:35 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_point ray_position(t_ray ray, float f)
{
    t_point point;
    
    point.tuple = tuples_add(ray.origin.tuple, ray.direction.tuple);
    return (point);
}