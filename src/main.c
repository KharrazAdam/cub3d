/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/26 12:14:22 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

int main(void)
{
	// t_matrice	scal;
	t_matrice	trans;
	t_point p;
	t_vector v;

    trans = matrice_rotat_y(M_PI_4 );
	// scal = matrice_scaling(2, 3, 4);
	p.tuple = tuple_initializer(0, 0, 1, 1);
	v.tuple = tuple_initializer(2, 3, 4, 0);

	tuple_print(matrice_tuple_multiplication((trans), p.tuple));
}

/**
 * !as
 * ?sada
 * TODO ds
 * * dfgdfs
 * // fdsfsdfs
 * //! dfgdhiofgjld
*/
