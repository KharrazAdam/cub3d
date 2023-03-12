/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 05:13:35 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 23:19:35 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	fill_cy_diametre(char *param, t_cylinder *cy)
{
	if (check_float(param) == false)
		return (false);
	cy->diameter = ft_atof(param);
	return (true);
}

static bool	fill_cy_height(char *param, t_cylinder *cy)
{
	if (check_float(param) == false)
		return (false);
	cy->height = ft_atof(param);
	return (true);
}

static bool	fill_cy_colour(char *param, t_cylinder *cy)
{
	char		**spl;
	short		i;

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
	cy->col = colour_initializer(ft_atoi(spl[0]), \
	ft_atoi(spl[1]), ft_atoi(spl[2]));
	return (clear(spl), true);
}

bool	cf_cy(char **par, t_list **cls)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	if (!cy)
		return (false);
	if (count_att(par) != 6)
		return (free(cy), ft_putendl_fd \
		("Error\nCylindre's attributes!", 2), false);
	if (fill_cy_position(par[1], cy) == false)
		return (free(cy), ft_putstr_fd \
		("Error\nCylindre's Position!\n", 2), false);
	if (fill_cy_direction(par[2], cy) == false)
		return (free(cy), ft_putstr_fd \
		("Error\nCylindre's Directon!\n", 2), false);
	if (fill_cy_diametre(par[3], cy) == false)
		return (free(cy), ft_putstr_fd \
		("Error\nCylindre's Diametre!\n", 2), false);
	if (fill_cy_height(par[4], cy) == false)
		return (free(cy), ft_putstr_fd("Error\nCylindre's Height!\n", 2), false);
	if (fill_cy_colour(par[5], cy) == false)
		return (free(cy), ft_putstr_fd("Error\nCylindre's Colour!\n", 2), false);
	ft_lstadd_back(cls, ft_lstnew(cy));
	return (true);
}
