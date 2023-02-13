/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/13 03:18:08 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void    print_tuple(t_tuple sum)
{
    printf("x -> %f, y -> %f, z -> %f, w -> %f", sum.x, sum.y, sum.z, sum.w);
}

int main(void)
{
    t_tuple a;
    t_tuple b;
    
    a.x = 12; a.y = 41; a.z = 32; a.w = 0;
    b.x = -1; b.y = -2; b.z = -3; b.w = 0;

    printf("%f\n", magnitude(b));
    t_tuple sum = add_tuples(a, b);
    print_tuple(sum);
    return (0);
}
