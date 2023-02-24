/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_inverting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:51:18 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/24 16:13:13 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

float   matrice_det(t_matrice mat)
{
    return (mat.mat[0][0] * mat.mat[1][1] * mat.mat[2][2] * mat.mat[3][3])
    - (mat.mat[0][0] * mat.mat[1][1] * mat.mat[2][3] * mat.mat[3][2])
    - (mat.mat[0][0] * mat.mat[1][2] * mat.mat[2][1] * mat.mat[3][3])
    + (mat.mat[0][0] * mat.mat[1][2] * mat.mat[2][3] * mat.mat[3][1])
    + (mat.mat[0][0] * mat.mat[1][3] * mat.mat[2][1] * mat.mat[3][2])
    - (mat.mat[0][0] * mat.mat[1][3] * mat.mat[2][2] * mat.mat[3][1])
    - (mat.mat[0][1] * mat.mat[1][0] * mat.mat[2][2] * mat.mat[3][3])
    + (mat.mat[0][1] * mat.mat[1][0] * mat.mat[2][3] * mat.mat[3][2])
    + (mat.mat[0][1] * mat.mat[1][2] * mat.mat[2][0] * mat.mat[3][3])
    - (mat.mat[0][1] * mat.mat[1][2] * mat.mat[2][3] * mat.mat[3][0])
    - (mat.mat[0][1] * mat.mat[1][3] * mat.mat[2][0] * mat.mat[3][2])
    + (mat.mat[0][1] * mat.mat[1][3] * mat.mat[2][2] * mat.mat[3][0])
    + (mat.mat[0][2] * mat.mat[1][0] * mat.mat[2][1] * mat.mat[3][3])
    - (mat.mat[0][2] * mat.mat[1][0] * mat.mat[2][3] * mat.mat[3][1])
    - (mat.mat[0][2] * mat.mat[1][1] * mat.mat[2][0] * mat.mat[3][3])
    + (mat.mat[0][2] * mat.mat[1][1] * mat.mat[2][3] * mat.mat[3][0])
    + (mat.mat[0][2] * mat.mat[1][3] * mat.mat[2][0] * mat.mat[3][1])
    - (mat.mat[0][2] * mat.mat[1][3] * mat.mat[2][1] * mat.mat[3][0])
    - (mat.mat[0][3] * mat.mat[1][0] * mat.mat[2][1] * mat.mat[3][2])
    + (mat.mat[0][3] * mat.mat[1][0] * mat.mat[2][2] * mat.mat[3][1])
    + (mat.mat[0][3] * mat.mat[1][1] * mat.mat[2][0] * mat.mat[3][2])
    - (mat.mat[0][3] * mat.mat[1][1] * mat.mat[2][2] * mat.mat[3][0])
    - (mat.mat[0][3] * mat.mat[1][2] * mat.mat[2][0] * mat.mat[3][1])
    + (mat.mat[0][3] * mat.mat[1][2] * mat.mat[2][1] * mat.mat[3][0]);
}

t_matrice   matrice_inverse(t_matrice mat)
{
    t_matrice ret;

    return ret;
};