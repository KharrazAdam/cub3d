/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:17:03 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/21 00:51:58 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
#define CANVAS_H

#include "ray.h"

typedef struct s_canvas
{
	int			width;
	int			height;
	t_colour	**pix;
}t_canvas;

t_canvas	canvas_initializer(int, int);
void		canvas_print_rgb(t_canvas can);
void		canvas_insert(t_canvas *can, int y, int x, t_colour col);
t_colour	canvas_pix(t_canvas can, int x, int y);

#endif // CANVAS_H
