/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/28 19:02:27 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

int main(void)
{
	t_matrice	trans;
	t_point p;
	t_vector v;

    // trans = matrice_rotat_y(M_PI_4 );
	// trans = matrice_scaling(2, 3, 4);
	float   x[2] = {0, 0};
	float   y[2] = {0, 1};
	float   z[2] = {0, 0};
    
    trans = matrice_shearing(x, y, z);
	p.tuple = tuple_initializer(2, 3, 4, 1);
	v.tuple = tuple_initializer(2, 3, 4, 0);

	tuple_print(matrice_tuple_multiplication((trans), p.tuple));
}

// /**
//  * !as
//  * ?sada
//  * TODO ds
//  * * dfgdfs
//  * // fdsfsdfs
//  * //! dfgdhiofgjld
// */
