/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/24 23:45:33 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

int main(void)
{
    float f[4][4];

    tab_init_1(f);
    t_matrice mat = matrice_init(f);
    matrice_sub(&mat, 1, 3);
    printf("---%f---\n", matrice_det(mat));
    matrice_show(mat);
    printf("-----------------------\n");
    // matrice_show(matrice_inverse(mat));
    matrice_show(matrice_inverse(mat));
    printf("-----------------------\n");
}
