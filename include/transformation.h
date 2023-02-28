/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:48:50 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/26 15:45:25 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "matrice.h"

/**
 * *Translation
 * @brief move a point.
*/
t_matrice	matrice_translation(float x, float y, float z);

/**
 * *Scaling
*/
t_matrice	matrice_scaling(float x, float y, float z);

/**
 * *Rotation
*/
t_matrice	matrice_rotat_x(float r);
t_matrice	matrice_rotat_y(float r);
t_matrice	matrice_rotat_z(float r);
/**
 * *Shering
*/
t_matrice   matrice_shearing(float x[2], float y[2], float z[2]); // shearing(xy, xz, yx, yz, zx, zy)
#endif
