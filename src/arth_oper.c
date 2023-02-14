/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arth_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:46:19 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/14 19:19:04 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_tuple	add_tuples(t_tuple f_addend, t_tuple s_addend)
{
    t_tuple sum;

    sum.x = f_addend.x + s_addend.x;
    sum.y = f_addend.y + s_addend.y;
    sum.z = f_addend.z + s_addend.z;
    sum.w = f_addend.w + s_addend.w;
    return (sum);
}

t_tuple	Subtracting_tuples(t_tuple minuend, t_tuple subtrahend)
{
    t_tuple sub;

    sub.x = minuend.x - subtrahend.x;
    sub.y = minuend.y - subtrahend.y;
    sub.z = minuend.z - subtrahend.z;
    sub.w = minuend.w - subtrahend.w;
    return (sub);
}
