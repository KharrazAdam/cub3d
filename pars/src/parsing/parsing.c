/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:32:05 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/21 11:56:26 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

int	parsing(t_map *map, char *av)
{
	int	fd;

	fd = check_file(av);
	if (fd < 0)
		return (1);
	if (check_elements(map, fd) == false)
		return  (1);
	if (check_map(map, fd) == false)
		return (clear_attr(map), system("leaks Cub3d"),1);
	close(fd);
	return (0);
}