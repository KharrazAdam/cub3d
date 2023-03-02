/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:22:13 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/28 21:31:22 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_colour	colour_add(t_colour f_addend, t_colour s_addend)
{   
    t_colour    ret;

    ret.tuple = tuples_add(f_addend.tuple, s_addend.tuple);
    return ret;
}

t_colour	colour_Subtracting(t_colour minuend, t_colour subtrahend)
{
    t_colour    ret;

    ret.tuple = tuples_Subtracting(minuend.tuple, subtrahend.tuple);
    return ret;
    
}

t_colour	colour_scalar_product(t_colour multiplicand, float scale)
{
    t_colour ret;

    ret.tuple = tuple_scalar_multipli(multiplicand.tuple, scale);
    return ret;
}

t_colour	colour_multiplying(t_colour multiplicand, t_colour multiplier)
{
    t_colour    ret;

    ret.tuple.x = multiplicand.tuple.x * multiplier.tuple.x;
    ret.tuple.y = multiplicand.tuple.y * multiplier.tuple.y;
    ret.tuple.z = multiplicand.tuple.z * multiplier.tuple.z;
    return ret;
}
