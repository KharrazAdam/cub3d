/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_magnitude.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:10:14 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:47:31 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float   magnitude(t_tuple tup)
{
	return (sqrtf(pow(tup.x, 2) + pow(tup.y, 2) \
	+ pow(tup.z, 2) + pow(tup.w, 2)));
}
