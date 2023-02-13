/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:40:46 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/13 02:49:21 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
#define TUPLE_H

typedef struct tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}t_tuple;



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
#endif // TUPLE