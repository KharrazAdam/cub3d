/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:36:54 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/20 02:21:07 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curent;
	t_list	*next;

	curent = *lst;
	while (curent)
	{
		next = curent->next;
		ft_lstdelone(curent, del);
		curent = next;
	}
	*lst = NULL;
	free(lst);
}
