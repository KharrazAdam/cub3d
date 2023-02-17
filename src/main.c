/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/17 11:17:05 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void    print_tuple(t_tuple sum)
{
	printf("x -> %f, y -> %f, z -> %f, w -> %f\n", sum.x, sum.y, sum.z, sum.w);
}

int main(void)
{
	t_colour	colour1 = colour_initializer(0, 0, 1);
    t_canvas    can;

    can = canvas_initializer(10, 5);
    canvas_insert(&can, 0, 1, colour1);
    canvas_print(can);
    printf("{%d}\n", canvas_pix(can, 0, 1).rgb);
	return (0);
}
