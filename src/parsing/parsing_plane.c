/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 04:37:37 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 23:04:14 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	cf_plane(char **par, t_list **pls)
{
	t_plane	*pln;

	pln = malloc(sizeof(t_plane));
	if (!pln)
		return (false);
	if (count_att(par) != 4)
		return (free(pln), ft_putstr_fd \
		("Error\nPlane attributes number!\n", 2), false);
	if (fill_plane_position(par[1], pln) == false)
		return (free(pln), ft_putstr_fd("Error\nPlane Position!\n", 2), false);
	if (fill_plane_direction(par[2], pln) == false)
		return (free(pln), ft_putstr_fd("Error\nPlane Direction!\n", 2), false);
	if (fill_plane_colour(par[3], pln) == false)
		return (free(pln), ft_putstr_fd("Error\nPlane Colour!\n", 2), false);
	ft_lstadd_back(pls, ft_lstnew(pln));
	return (true);
}
