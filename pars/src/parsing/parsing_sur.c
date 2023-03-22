/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 04:24:12 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/21 04:59:32 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static bool	sur_check_e(int i, int j, char **map)
{
	while (map[i][j])
	{
		if (map[i][j] == ' ')
			break ;
		if (map[i][j] == '1')
			return (true);
		j++;
	}
	ft_putendl_fd("Error\nmap is not surrounded by walls to east", 2);
	return (false);
}

static bool	sur_check_w(int i, int j, char **map)
{
	while (j >= 0)
	{
		if (map[i][j] == ' ' || map[i][j] == '%')
			break ;
		if (map[i][j] == '1')
			return (true);
		j--;
	}
	ft_putendl_fd("Error\nmap is not surrounded by walls to west", 2);
	return (false);
}

static bool	sur_check_n(int i, int j, char **map)
{
	while (i >= 0)
	{
		if (map[i][j] == ' ' || map[i][j] == '%')
			break ;
		if (map[i][j] == '1')
			return (true);
		i--;
	}
	ft_putendl_fd("Error\nmap is not surrounded by walls to north", 2);
	return (false);
}

static bool	sur_check_s(int i, int j, char **map)
{
	while (map[i])
	{
		if (map[i][j] == ' ' || map[i][j] == '%')
			break ;
		if (map[i][j] == '1')
			return (true);
		i++;
	}
	ft_putendl_fd("Error\nmap is not surrounded by walls to south", 2);
	return (false);
}

bool	sur_check(int i, int j, char **map)
{
	if (sur_check_e(i, j, map) == false)
		return (false);
	if (sur_check_w(i, j, map) == false)
		return (false);
	if (sur_check_n(i, j, map) == false)
		return (false);
	if (sur_check_s(i, j, map) == false)
		return (false);
	return (true);
}
