/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 02:42:41 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/20 02:43:45 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	check_valid(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	if (size < 4)
		return (false);
	if (ft_strncmp(str + (size - 4), ".cub", 5))
		return (false);
	return (true);
}

int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDWR);
	if (fd < 0)
		return (ft_putendl_fd("Error\nfile does not exist!", 2), -1);
	if (check_valid(str) == false)
		return (ft_putendl_fd("Error\nfile is not valid!", 2), -1);
	return (fd);
}