/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_rbg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:18:59 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/17 03:16:21 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void	colour_rbg(t_colour *col)
{
	col->rgb = 0;
	col->rgb += (int)(col->tuple.x * 255) << 16 | (int)(col->tuple.y * 255) << 8 | (int)(col->tuple.z * 255);
}
