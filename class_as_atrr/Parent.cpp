/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parent.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:52:55 by akharraz          #+#    #+#             */
/*   Updated: 2022/12/09 10:10:33 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parent.hpp"

void	Parent::set(int i)
{
	child[i].set_child();
}

void	Parent::get(int i)
{
	child[i].get_child();
}
