/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:18:59 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/17 11:08:13 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_colour	colour_initializer(float x, float y, float z)
{
    t_colour ret;

	ret.tuple = tuple_initializer(x, y, z, 0);
    ret.rgb = 0;
    ret.rgb += (int)(ret.tuple.x * 255) << 16 | (int)(ret.tuple.y * 255) << 8 | (int)(ret.tuple.z * 255);
    return (ret);
}
