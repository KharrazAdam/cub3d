/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:16:31 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 23:21:18 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	cy_dir_is_valid(float x)
{
	return (x <= 1 && x >= -1);
}

bool	fill_cy_position(char *param, t_cylinder *cy)
{
	char	**spl;
	short	i;

	spl = ft_split(param, ',');
	if (!spl)
		return (false);
	if (count_att(spl) != 3)
		return (clear(spl), false);
	i = 0;
	while (spl[i])
	{
		if (check_float(spl[i]) == false)
			return (clear(spl), false);
		i++;
	}
	cy->position = point_initializer(ft_atof(spl[0]), \
	ft_atof(spl[1]), ft_atof(spl[2]));
	return (clear(spl), true);
}

static bool	cy_fill_dir_value(t_cylinder *cy, char **spl)
{
	int		i;

	i = 0;
	while (spl[i])
	{
		if (check_float(spl[i]) == false)
			return (false);
		i++;
	}
	cy->direction.tuple.x = ft_atof(spl[0]);
	if (cy_dir_is_valid(cy->direction.tuple.x) == false)
		return (false);
	cy->direction.tuple.y = ft_atof(spl[1]);
	if (cy_dir_is_valid(cy->direction.tuple.y) == false)
		return (false);
	cy->direction.tuple.z = ft_atof(spl[2]);
	if (cy_dir_is_valid(cy->direction.tuple.z) == false)
		return (false);
	return (true);
}

bool	fill_cy_direction(char *param, t_cylinder *cy)
{
	char	**spl;

	spl = ft_split(param, ',');
	if (!spl)
		return (false);
	if (count_att(spl) != 3)
		return (clear(spl), false);
	if (cy_fill_dir_value(cy, spl) == false)
		return (clear(spl), false);
	return (clear(spl), true);
}
