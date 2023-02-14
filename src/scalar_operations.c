/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:01:45 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/14 17:10:23 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_tuple	scalar_multipli(t_tuple factor, float scale)
{
    t_tuple product;

    product.x = factor.x * scale;
    product.y = factor.y * scale;
    product.z = factor.z * scale;
    product.w = factor.w * scale;
    return (product);
}

t_tuple	scalar_deviding(t_tuple factor, float scale)
{
    t_tuple product;

    product.x = factor.x / scale;
    product.y = factor.y / scale;
    product.z = factor.z / scale;
    product.w = factor.w / scale;
    return (product);
}
