/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:40:46 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/01 23:01:16 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
#define TUPLE_H

#include <stdbool.h>
#include <math.h>
typedef struct s_tuple
{
	float	x; // red
	float	y; // green
	float	z; // blue
	float	w;
}t_tuple;

typedef struct s_colour
{
	t_tuple tuple;
	t_tuple values;
	int     rgb;
}t_colour;

typedef struct vector
{
	t_tuple tuple;
} t_vector;

typedef struct point
{
	t_tuple tuple;
} t_point;

// tuple init
t_tuple		tuple_initializer(float, float, float, float);
t_point     point_initializer(float x, float y, float z);
t_vector    vetor_initializer(float x, float y, float z);
		/*operations on tuples*/
// arithmitic operations
t_tuple     tuples_add(t_tuple, t_tuple);
t_tuple     tuples_Subtracting(t_tuple, t_tuple);
bool        tuples_equal(t_tuple a, t_tuple b);
// tuples_negating
t_tuple     tuples_negating(t_tuple);
// scalar operations
t_tuple     tuple_scalar_multipli(t_tuple, float);
t_tuple     tuple_scalar_deviding(t_tuple, float);
// magnitude
float       magnitude(t_tuple);
// normalization
t_tuple     nrml(t_tuple);
// production operations
float		tuple_dot_product(t_tuple, t_tuple);
t_tuple		cross_product(t_tuple, t_tuple);
void        tuple_print(t_tuple sum);
		/*operations on colours*/
t_colour	colour_initializer(float x, float y, float z);
t_colour	colours_add(t_colour, t_colour);
t_colour	colours_Subtracting(t_colour, t_colour);
t_colour	colours_scalar_product(t_colour, float);
t_colour	colours_multiplying(t_colour, t_colour); // hadamard_product


#endif // TUPLE