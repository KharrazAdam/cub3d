/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 06:19:03 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/10 20:56:48 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

size_t	count_att(char **attr)
{
	size_t	i;

	i = 0;
	while (attr[i])
		i++;
	return (i);
}

void	lst_pop_node(t_list **lst, t_list *node)
{
	t_list	*n;
	t_list	*tmp;

	n = *lst;
	if (n == node)
	{
		tmp = node;
		*lst = n->next;
		ft_lstdelone(tmp, free);
	}
	while (n->next && n->next != node)
		n = n->next;
	if (n->next)
	{
		tmp = n->next;
		n->next = n->next->next;
		ft_lstdelone(tmp, free);
	}
}

int	check_rgb(char **rgb)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (rgb[i])
	{
		j = -1;
		while (rgb[i][++j])
			if (!ft_isdigit(rgb[i][j]) && rgb[i][j] != '\n')
				return (0);
		tmp = ft_atoi(rgb[i++]);
		if (tmp > 255)
			return (0);
	}
	return (1);
}
