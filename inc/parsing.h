/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 02:17:51 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/20 09:21:28 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "cub3d.h"

# include <stdbool.h>

# define NO 1
# define SO 2
# define EA 4
# define WE 8
# define F 16
# define C 32

/**
 * I- parsing in files
 * check if file exists 
 * check its extension
*/
bool	check_valid(char *str);
int		check_file(char *str);

#endif