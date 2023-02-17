/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:11:05 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/13 05:20:21 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ray.h"

float		dot_product(t_tuple f_tup, t_tuple s_tup)
{
    float ret;

    ret = (f_tup.x * s_tup.x) + (f_tup.y * s_tup.y) + (f_tup.z * s_tup.z) + (f_tup.w * s_tup.w);
    return (ret);
}

t_tuple		cross_product(t_tuple one, t_tuple two)
{
    t_tuple ret;

    ret.x = one.y * two.z - one.z * two.y;
    ret.y = one.z * two.x - one.x * two.z;
    ret.z = one.x * two.y - one.y * two.x;
    return ret;
}
