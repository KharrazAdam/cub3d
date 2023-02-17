/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:17:03 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/17 10:42:17 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
#define CANVAS_H

#include "ray.h"

typedef struct s_canvas
{
    int         width;
    int         height;
    t_colour    **pix;
}t_canvas;

t_canvas    *canvas_initializer(int, int);
void    	canvas_print(t_canvas can);
void        canvas_insert(t_canvas *can, int y, int x, t_colour col);
#endif // CANVAS_H
