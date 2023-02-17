/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:50:51 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/17 11:16:54 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void    canvas_insert(t_canvas *can, int y, int x, t_colour col)
{
   can->pix[y][x] = colour_initializer(col.tuple.x, col.tuple.y, col.tuple.z);
}

t_colour    canvas_pix(t_canvas can, int y, int x)
{
    return  can.pix[y][x];
}
void	canvas_print(t_canvas can)
{
	int	x;
	int	y;

	y = 0;
	while (y < can.height)
	{
		x = 0;
		while (x < can.width)
		{
            ft_putnbr_fd(can.pix[y][x].rgb, 1);
			ft_putchar_fd(' ', 1);
			x++;
		}
			ft_putchar_fd('\n', 1);
		y++;
	}
}

t_canvas    canvas_initializer(int w, int h)
{
	t_canvas	can;
	int			x;
	int			y;

	y = 0;
	can.width = w;
	can.height = h;
	can.pix = malloc(sizeof(t_colour *) * (h + 1));
	while (y < can.height)
	{
		x = 0;
		can.pix[y] = malloc(sizeof(t_colour) * (w + 1));
		while (x < can.width)
		{
            can.pix[y][x] = colour_initializer(0, 0, 0);
			x++;
		}
		y++;
	}
	can.pix[y] = NULL;
	return (can);
}
 