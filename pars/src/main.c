/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:42:12 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/21 11:58:44 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_map map;

	ft_bzero(&map, sizeof(t_map));
	if (ac != 2)
		return (ft_putendl_fd("Error\nnumber of argumants must be 2!", 2), 1);
	if (parsing(&map, av[1]) == 1)
		return (1);
	return (0);
}
