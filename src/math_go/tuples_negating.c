/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_negating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:19:33 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:47:39 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tuple	tuples_negating(t_tuple tup)
{
	t_tuple	neg;

	neg.x = -tup.x;
	neg.y = -tup.y;
	neg.z = -tup.z;
	neg.w = -tup.w;
	return (neg);
}
