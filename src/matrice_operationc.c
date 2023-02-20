/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_operationc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:21:34 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/20 05:21:25 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

static float	set_val(float *a, t_matrice b, int x)
{
	int		var;
	float	ret;

	var = -1;
	ret = 0;
	while (++var < 4)
		ret += (a[var] * b.mat[var][x]);
	return (ret);	
}

t_matrice   matrices_multiplication(t_matrice a, t_matrice b)
{
	t_matrice	ret;
	int			y;
	int			x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ret.mat[y][x] = set_val(a.mat[y], b, x);
			x++;
		}
		y++;
	}
	return (ret);
}

t_tuple matrice_tuple_multiplication(t_matrice mat, t_tuple tup)
{
	t_tuple ret;

	ret.x = (mat.mat[0][0] * tup.x) + (mat.mat[0][1] * tup.y) + (mat.mat[0][2] * tup.z) + (mat.mat[0][3] * tup.w);
	ret.y = (mat.mat[1][0] * tup.x) + (mat.mat[1][1] * tup.y) + (mat.mat[1][2] * tup.z) + (mat.mat[1][3] * tup.w);
	ret.z = (mat.mat[2][0] * tup.x) + (mat.mat[2][1] * tup.y) + (mat.mat[2][2] * tup.z) + (mat.mat[2][3] * tup.w);
	ret.w = (mat.mat[3][0] * tup.x) + (mat.mat[3][1] * tup.y) + (mat.mat[2][2] * tup.z) + (mat.mat[3][3] * tup.w);
	return ret;
}