/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:52:34 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/14 09:17:10 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

#include "tuple.h"

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}t_projectile;

typedef struct s_environment
{
	t_tuple	gravity;
	t_tuple	wind;
}t_environment;

typedef struct s_vars
{
    void    *mlx;
    void    *win;
}t_vars;


void	tick(t_projectile* proj, t_environment* env);

#endif // TYPES_H
