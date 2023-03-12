/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:41:21 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/10 22:57:48 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	ft_atof(const char *str)
{
	int		sign;
	double	result;
	int		i;
	float	scale;

	sign = 1;
	i = 0;
	result = 0.0;
	scale = 1.0;
	if (str[i] == '-' && str[i++])
		sign = -1;
	while (str[i] && str[i] != '.')
	{
		result = result * 10 + (double)(str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		while (str[++i])
		{
			scale /= 10;
			result += scale * (double)(str[i] - '0');
		}
	}
	return (sign * result);
}
