/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_arth_oper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:46:19 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:46:20 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tuple	tuples_add(t_tuple f_addend, t_tuple s_addend)
{
	t_tuple sum;

	sum.x = f_addend.x + s_addend.x;
	sum.y = f_addend.y + s_addend.y;
	sum.z = f_addend.z + s_addend.z;
	sum.w = f_addend.w + s_addend.w;
	return (sum);
}

t_tuple	tuples_Subtracting(t_tuple minuend, t_tuple subtrahend)
{
	t_tuple sub;

	sub.x = minuend.x - subtrahend.x;
	sub.y = minuend.y - subtrahend.y;
	sub.z = minuend.z - subtrahend.z;
	sub.w = minuend.w - subtrahend.w;
	return (sub);
}

bool	tuples_equal(t_tuple a, t_tuple b)
{
	if (fabs(a.x - b.x) < EPSILON)
		return (false);
	else if (fabs(a.y - b.y) < EPSILON)
		return (false);
	else if (fabs(a.z - b.z) < EPSILON)
		return (false);
	else if (fabs(a.w - b.w) < EPSILON)
		return (false);
	return (true);
}