/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/20 06:34:33 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

int main(void)
{
    float fl[4][4];
    t_tuple     tup = tuple_initializer(1, 2, 3, 1);
    t_matrice   mat;
    tab_init_1(fl);
    mat = matrice_init(fl);
    tuple_print(matrice_tuple_multiplication(mat, tup));
    matrice_show(matrice_identity());
    printf("\n");
    matrice_show(matrice_transpose(matrice_identity()));
}
