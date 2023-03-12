/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:04:21 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/10 20:53:41 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_float(const char *num)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (num[i] && num[i] != '\n')
	{
		if (!ft_isdigit(num[i]) && num[i] != '-' && num[i] != '.')
			return (0);
		if (num[i] == '.')
			j++;
		if (num[i] == '-')
			k++;
		i++;
	}
	if (k > 1 || j > 1)
		return (0);
	return (1);
}

int	is_shape(char *shape)
{
	return (ft_strncmp("cy", shape, 3) && ft_strncmp("pl", shape, 3)
		&& ft_strncmp("sp", shape, 3));
}
