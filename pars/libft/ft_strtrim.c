/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:11:58 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/21 11:11:20 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	begining(char const *s1, char const *set)
{
	int	x;

	x = 0;
	while (s1[x])
	{
		if (ft_strchr(set, s1[x]) == 0)
			return (x);
		x++;
	}
	return (0);
}

static int	ending(char const *s1, char const *set)
{
	int	y;

	y = ft_strlen(s1);
	while (y >= 0)
	{
		if (ft_strrchr(set, s1[y]) == 0)
			return (y);
		y--;
	}
	return (y);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		a;
	int		b;

	if (!s1 || !set)
		return (NULL);
	a = ending(s1, set);
	b = begining(s1, set);
	new = ft_substr(s1, b, a - b + 1);
	if (new == 0)
		return (NULL);
	return (new);
}
