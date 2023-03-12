/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:38:49 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:19:13 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	fill_sphere_position(char *param, t_sphere *sph)
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
	sph->position = point_initializer(ft_atof(spl[0]), \
	ft_atof(spl[1]), ft_atof(spl[2]));
	return (clear(spl), true);
}

static bool	sph_dm(char *param, t_sphere *sph)
{
	if (check_float(param) == false)
		return (false);
	sph->diameter = ft_atof(param);
	return (true);
}

static bool	sph_colour(char *param, t_sphere *sph)
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
	sph->col = colour_initializer(ft_atoi(spl[0]), \
	ft_atoi(spl[1]), ft_atoi(spl[2]));
	return (clear(spl), true);
}

bool	cf_sphere(char **par, t_list **sps)
{
	t_sphere	*sph;

	sph = malloc(sizeof(t_sphere));
	if (!sph)
		return (false);
	if (count_att(par) != 4)
		return (printf("Error\nSphere's attributes number!\n"), free(sph), false);
	if (fill_sphere_position(par[1], sph) == false)
		return (free(sph), printf("Error\nSphere's Position!\n"), false);
	if (sph_dm(par[2], sph) == false)
		return (free(sph), printf("Error\nSphere's Diameter!\n"), false);
	if (sph_colour(par[3], sph) == false)
		return (free(sph), printf("Error\nSphere's Colour!\n"), false);
	ft_lstadd_back(sps, ft_lstnew(sph));
	return (true);
}
