/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plane_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:04:26 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 23:15:05 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	fill_plane_position(char *param, t_plane *pln)
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
	pln->position = point_initializer(ft_atof(spl[0]), \
	ft_atof(spl[1]), ft_atof(spl[2]));
	return (clear(spl), true);
}

static bool	pl_dir_is_valid(float x)
{
	return (x <= 1 && x >= -1);
}

static bool	fill_dir_value(t_plane *pln, char **spl)
{
	int		i;

	i = 0;
	while (spl[i])
	{
		if (check_float(spl[i]) == false)
			return (false);
		i++;
	}
	pln->direction.tuple.x = ft_atof(spl[0]);
	if (pl_dir_is_valid(pln->direction.tuple.x) == false)
		return (false);
	pln->direction.tuple.y = ft_atof(spl[1]);
	if (pl_dir_is_valid(pln->direction.tuple.y) == false)
		return (false);
	pln->direction.tuple.z = ft_atof(spl[2]);
	if (pl_dir_is_valid(pln->direction.tuple.z) == false)
		return (false);
	return (true);
}

bool	fill_plane_direction(char *param, t_plane *pln)
{
	char	**spl;

	spl = ft_split(param, ',');
	if (!spl)
		return (false);
	if (count_att(spl) != 3)
		return (clear(spl), false);
	if (fill_dir_value(pln, spl) == false)
		return (clear(spl), false);
	return (clear(spl), true);
}

bool	fill_plane_colour(char *param, t_plane *pln)
{
	char	**spl;
	short	i;

	i = 0;
	spl = ft_split(param, ',');
	if (!spl)
		return (false);
	if (count_att(spl) != 3)
		return (clear(spl), false);
	while (spl[i])
	{
		if (check_float(spl[i]) == false)
			return (clear(spl), false);
		i++;
	}
	pln->col = colour_initializer(ft_atoi(spl[0]), ft_atoi(spl[1]), \
	ft_atoi(spl[2]));
	return (clear(spl), true);
}
