/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_inverting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:51:18 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/24 23:15:46 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

float	matrice_det(t_matrice mat)
{
	return (
		+ (mat.mat[0][0] * mat.mat[1][1] * mat.mat[2][2] * mat.mat[3][3])
	+ (mat.mat[0][0] * mat.mat[1][2] * mat.mat[2][3] * mat.mat[3][1])
	+ (mat.mat[0][0] * mat.mat[1][3] * mat.mat[2][1] * mat.mat[3][2])
	+ (mat.mat[0][1] * mat.mat[1][0] * mat.mat[2][3] * mat.mat[3][2])
	+ (mat.mat[0][1] * mat.mat[1][2] * mat.mat[2][0] * mat.mat[3][3])
	+ (mat.mat[0][1] * mat.mat[1][3] * mat.mat[2][2] * mat.mat[3][0])
	+ (mat.mat[0][2] * mat.mat[1][0] * mat.mat[2][1] * mat.mat[3][3])
	+ (mat.mat[0][2] * mat.mat[1][1] * mat.mat[2][3] * mat.mat[3][0])
	+ (mat.mat[0][2] * mat.mat[1][3] * mat.mat[2][0] * mat.mat[3][1])
	+ (mat.mat[0][3] * mat.mat[1][0] * mat.mat[2][2] * mat.mat[3][1])
	+ (mat.mat[0][3] * mat.mat[1][1] * mat.mat[2][0] * mat.mat[3][2])
	+ (mat.mat[0][3] * mat.mat[1][2] * mat.mat[2][1] * mat.mat[3][0])
	- (mat.mat[0][0] * mat.mat[1][1] * mat.mat[2][3] * mat.mat[3][2])
	- (mat.mat[0][0] * mat.mat[1][2] * mat.mat[2][1] * mat.mat[3][3])
	- (mat.mat[0][0] * mat.mat[1][3] * mat.mat[2][2] * mat.mat[3][1])
	- (mat.mat[0][1] * mat.mat[1][0] * mat.mat[2][2] * mat.mat[3][3])
	- (mat.mat[0][1] * mat.mat[1][2] * mat.mat[2][3] * mat.mat[3][0])
	- (mat.mat[0][1] * mat.mat[1][3] * mat.mat[2][0] * mat.mat[3][2])
	- (mat.mat[0][2] * mat.mat[1][0] * mat.mat[2][3] * mat.mat[3][1])
	- (mat.mat[0][2] * mat.mat[1][1] * mat.mat[2][0] * mat.mat[3][3])
	- (mat.mat[0][2] * mat.mat[1][3] * mat.mat[2][1] * mat.mat[3][0])
	- (mat.mat[0][3] * mat.mat[1][0] * mat.mat[2][1] * mat.mat[3][2])
	- (mat.mat[0][3] * mat.mat[1][1] * mat.mat[2][2] * mat.mat[3][0])
	- (mat.mat[0][3] * mat.mat[1][2] * mat.mat[2][0] * mat.mat[3][1]));
}

float	matrice_sub_det(float	fl[3][3])
{ 
	return ((fl[0][0] * fl[1][1] * fl[2][2]) - (fl[0][0] * fl[1][2] *  fl[2][1]) + (fl[0][1] * fl[1][2] *  fl[2][0]) - (fl[0][1] * fl[1][0] * fl[2][2]) + (fl[0][2] * fl[1][0] * fl[2][1]) - (fl[0][2] * fl[1][1] * fl[2][0]));
}

void	matrice_sub(t_matrice *adj, int i, int j)
{
	int	y;
	int	x;
	int	col;
	int	row;

	y = 0;
	row = 0;
	while (y < 3)
	{
		if (i == y)
			row++;
		x = 0;
		col = 0;
		while (x < 3)
		{
			if (j == x)
				col++;
			adj->sub[y][x] = adj->mat[row][col];
			x++;
			col++;
		}
		y++;
		row++;
	}
}

t_matrice	matrice_adjugate(t_matrice mat)
{
	t_matrice	adj;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			// adj[i][j] = sub_det();
			j++;
		}
		i++;
	}
	return (adj);
}

t_matrice	matrice_inverse(t_matrice mat)
{
	t_matrice	adj;

	// adjugate of matrice mat
	adj = matrice_adjugate(mat);
	return (matrice_scalar_multi(matrice_transpose(mat), 1 / matrice_det(mat)));
}
