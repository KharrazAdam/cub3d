/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:13:17 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/11 00:53:46 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	clear_shapes(t_list **sps, t_list **cls, t_list **pls)
{
	ft_lstclear(sps, free);
	ft_lstclear(cls, free);
	ft_lstclear(pls, free);
}

static bool	check_shapes(char **spl, t_list **sps, t_list **cls, t_list **pls)
{
	if (!ft_strncmp(spl[0], "sp", 3))
	{
		if (cf_sphere(spl, sps) == false)
			return (false);
	}
	else if (!ft_strncmp(spl[0], "cy", 3))
	{
		if (cf_cy(spl, cls) == false)
			return (false);
	}
	else if (!ft_strncmp(spl[0], "pl", 3))
	{
		if (cf_plane(spl, pls) == false)
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	check_and_fill_shapes(t_list **rt_file, t_list **sps, \
		t_list **cls, t_list **pls)
{
	t_list	*tmp;
	char	**spl;

	spl = NULL;
	tmp = *rt_file;
	while (tmp)
	{
		spl = ft_split(tmp->content, ' ');
		if (spl == NULL)
			return (clear_shapes(sps, cls, pls), false);
		else
		{
			if (check_shapes(spl, sps, cls, pls) == false)
				return (clear(spl), clear_shapes(sps, cls, pls), false);
			clear(spl);
		}
		tmp = tmp->next;
	}
	return (true);
}
