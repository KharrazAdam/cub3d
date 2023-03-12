/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:11:58 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/06 23:49:16 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buff;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j && ft_strchr(set, s1[j]))
		j--;
	if (j <= i || !s1[0])
	{
		buff = ft_calloc(1, sizeof(char));
		return (buff);
	}
	buff = ft_calloc(j - i + 2, sizeof(char));
	if (!buff)
		return (0);
	l = j - i + 1;
	while (k < l)
		buff[k++] = s1[i++];
	return (buff);
}
