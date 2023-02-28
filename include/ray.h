/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:25:36 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/28 19:02:19 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>

# include "tuple.h"
# include "types.h"
# include "canvas.h"
# include "matrice.h"
# include "transformation.h"
# include "utils.h"

#define EPSILON 0.00001
typedef struct s_vars
{
	void    *mlx;
	void    *win;
}t_vars;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction; 
}t_ray;

t_ray   ray_init(t_point p, t_vector v);
t_point ray_position(t_ray r, float distance);

#endif // RAY_H