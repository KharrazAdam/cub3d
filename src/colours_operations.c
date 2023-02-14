/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:22:13 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/14 19:18:42 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_colour	add_colours(t_colour f_addend, t_colour s_addend)
{   
    t_colour    ret;

    ret.tuple = add_tuples(f_addend.tuple, s_addend.tuple);
    return ret;
}

t_colour	Subtracting_colours(t_colour minuend, t_colour subtrahend)
{
    t_colour    ret;

    ret.tuple = Subtracting_tuples(minuend.tuple, subtrahend.tuple);
    return ret;
    
}

t_colour	scalar_product_colours(t_colour multiplicand, float scale)
{
    t_colour ret;

    ret.tuple = scalar_multipli(multiplicand.tuple, scale);
    return ret;
}

t_colour	multiplying_colours(t_colour multiplicand, t_colour multiplier)
{
    t_colour    ret;

    ret.tuple.x = multiplicand.tuple.x * multiplier.tuple.x;
    ret.tuple.y = multiplicand.tuple.y * multiplier.tuple.y;
    ret.tuple.z = multiplicand.tuple.z * multiplier.tuple.z;
    return ret;    
}