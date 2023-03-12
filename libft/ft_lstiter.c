/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:08:56 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/10 20:44:40 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*curent;
	t_list	*next;

	curent = lst;
	if (!f)
		return ;
	while (curent)
	{
		next = curent->next;
		f(curent->content);
		curent = next;
	}
}
