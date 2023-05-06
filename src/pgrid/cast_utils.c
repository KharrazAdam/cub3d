/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:57:22 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/06 13:58:38 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


double	pyth(double x, double y, double x1, double y1)
{
	return (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
}

double	fix_ang(double angle)
{
	if (angle < 0)
		angle = angle + (2 * M_PI);
	else if (angle > 2 * M_PI)
		angle = angle - (2 * M_PI);
	return (angle);
}