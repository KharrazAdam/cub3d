/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:10:14 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/13 03:18:46 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

float magnitude(t_tuple tup)
{
    return sqrtf(pow(tup.x, 2) + pow(tup.y, 2) + pow(tup.z, 2) + pow(tup.w, 2));
}
