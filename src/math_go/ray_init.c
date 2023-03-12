/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:48:11 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:45:05 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	ray_init(t_point p, t_vector v)
{
	t_ray	ini;

	ini.origin = p;
	ini.direction = v;
	return (ini);
}
