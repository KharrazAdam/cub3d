/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:18:59 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:08:35 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_colour	colour_initializer(int x, int y, int z)
{
	t_colour	ret;

	ret.rgb = x << 16 | y << 8 | z;
	return (ret);
}
