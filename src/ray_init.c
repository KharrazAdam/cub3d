/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:48:11 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/28 17:14:58 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_ray   ray_init(t_point p, t_vector v)
{
	t_ray ini;

	ini.origin = p;
	ini.direction = v;
	return (ini);
}
