/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_transformation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:47:56 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:44:52 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrice	matrice_translation(float x, float y, float z)
{
	t_matrice	trans;

	trans = matrice_identity();
	trans.mat[0][3] = x;
	trans.mat[1][3] = y;
	trans.mat[2][3] = z;
	return (trans);
}

t_matrice	matrice_scaling(float x, float y, float z)
{
	t_matrice	scal;

	scal = matrice_identity();
	scal.mat[0][0] = x;
	scal.mat[1][1] = y;
	scal.mat[2][2] = z;
	return (scal);
}

t_matrice	matrice_rotat_x(float r)
{
	t_matrice	rot;

	rot = matrice_identity();
	rot.mat[1][1] = cos(r);
	rot.mat[1][2] = -sin(r);
	rot.mat[2][1] = sin(r);
	rot.mat[2][2] = cos(r);
	return (rot);
}

t_matrice	matrice_rotat_y(float r)
{
	t_matrice	rot;

	rot = matrice_identity();
	rot.mat[0][0] = cos(r);
	rot.mat[0][2] = sin(r);
	rot.mat[2][0] = -sin(r);
	rot.mat[2][2] = cos(r);
	return (rot);
}

t_matrice	matrice_rotat_z(float r)
{
	t_matrice	rot;

	rot = matrice_identity();
	rot.mat[0][0] = cos(r);
	rot.mat[0][1] = -sin(r);
	rot.mat[1][0] = sin(r);
	rot.mat[1][1] = cos(r);
	return (rot);
}

t_matrice	matrice_shearing(float x[2], float y[2], float z[2])
{
	t_matrice	  shear;

	shear = matrice_identity();
	shear.mat[0][1] = x[0];
	shear.mat[0][2] = x[1];
	shear.mat[1][0] = y[0];
	shear.mat[1][2] = y[1];
	shear.mat[1][0] = y[0];
	shear.mat[1][2] = y[1];
	return (shear);
}
