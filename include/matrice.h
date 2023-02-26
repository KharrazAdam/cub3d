/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:25:25 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/25 15:43:58 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

# include <stdbool.h>

typedef	struct	s_matrice
{
	float   mat[4][4];
	float   sub[3][3];
}t_matrice;

/** * 
 * TODO to be deleted
 * */
void		tab_init(float tab[4][4]);
void		tab_init_1(float tab[4][4]);

// print
void		matrice_show(t_matrice show);
void        matrice_sub_show(t_matrice show);
// matrice init
t_matrice	matrice_init(float a[4][4]);
t_matrice   matrice_scan(float grp[4][4]);
// equality
bool		matrice_equal(t_matrice a, t_matrice b);
// multiplication
t_matrice	matrices_multiplication(t_matrice a, t_matrice b);
t_tuple		matrice_tuple_multiplication(t_matrice mat, t_tuple tup);
t_matrice   matrice_scalar_multi(t_matrice mat, float scale);
// identity
t_matrice	matrice_identity(void);
// transpose
t_matrice	matrice_transpose(t_matrice mat);
//     determinant
float   matrice_det(t_matrice mat);
float	matrice_sub_det(float	fl[3][3]);
// inverting
void    	matrice_sub(t_matrice *adj, int i, int j);
t_matrice   matrice_adjugate(t_matrice mat);
t_matrice   matrice_inverse(t_matrice mat);
// adjugate
t_matrice	matrice_adjugate(t_matrice mat);
#endif // MATRICE_H