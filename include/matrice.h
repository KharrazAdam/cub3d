/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:25:25 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/20 05:16:02 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
#define MATRICE_H

#include <stdbool.h>
typedef struct s_matrice
{
    float mat[4][4];
}t_matrice;

t_matrice   matrice_init(float[4][4]);
void        tab_init(float tab[4][4]);
void        tab_init_1(float tab[4][4]);
bool        matrice_equal(t_matrice a, t_matrice b);
t_matrice   matrices_multiplication(t_matrice a, t_matrice b);
void        matrice_show(t_matrice show);
#endif // MATRICE_H