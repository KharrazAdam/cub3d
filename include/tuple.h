/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:40:46 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/14 15:17:51 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
#define TUPLE_H

typedef struct tuple
{
	float	x; // red
	float	y; // green
	float	z; // blue
	float	w;
}t_tuple;

typedef struct s_colour
{
    t_tuple tuple;
    int     colour;
}t_colour;

typedef struct vector
{
    t_tuple tuple;
} t_vector;

typedef struct point
{
    t_tuple tuple;
} t_point;

        /*operations on tuples*/
// arithmitic operations
t_tuple	add_tuples(t_tuple, t_tuple);
t_tuple	Subtracting_tuples(t_tuple, t_tuple);
// Negating
t_tuple	negating(t_tuple);
// scalar operations
t_tuple	scalar_multipli(t_tuple, float);
t_tuple	scalar_deviding(t_tuple, float);
// magnitude
float magnitude(t_tuple);
// normalization
t_tuple   nrml(t_tuple);
// production operations
float		dot_product(t_tuple, t_tuple);
t_tuple		cross_product(t_tuple, t_tuple);
t_tuple	    initialize_tuple(float, float, float, float);
void        print_tuple(t_tuple sum);
        /*operations on tuples*/
void    rbg(t_colour *);
#endif // TUPLE