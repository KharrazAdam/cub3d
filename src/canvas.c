/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:50:51 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/17 10:43:52 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void    canvas_insert(t_canvas *can, int y, int x, t_colour col)
{
    can->pix[y][x]= col;
}

void	canvas_print(t_canvas can)
{
	int	x;
	int	y;

	y = 0;
	while (y < can.height - 1)
	{
		x = 0;
		while (x < can.width - 1)
		{
            ft_putnbr_fd(can.pix[y][x].rgb, 1);
			ft_putchar_fd(' ', 1);
			x++;
		}
			ft_putchar_fd('\n', 1);
		y++;
	}
}

t_canvas    *canvas_initializer(int w, int h)
{
	t_canvas	*can;
	int			x;
	int			y;

	y = 0;
    can = malloc(sizeof(t_canvas));
	can->width = w;
	can->height = h;
	can->pix = malloc(sizeof(t_colour *) * (h + 1));
	while (y < can->height - 1)
	{
		x = 0;
		can->pix[y] = malloc(sizeof(t_colour) * (w + 1));
		while (x < can->width - 1)
		{
			colour_rbg(&can->pix[y][x]);
			can->pix[y][x].tuple = tuple_initializer(1, 1, 1, 0);
			x++;
		}
		can->pix[y] = NULL;
		y++;
	}
	return (can);
}
 