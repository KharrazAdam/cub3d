/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialzer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:11:21 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/14 09:11:38 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

t_tuple	initialize_tuple(float x, float y, float z, float w)
{
	t_tuple	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	ret.w = w;
    return ret;
}
