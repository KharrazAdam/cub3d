/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Child.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:59:38 by akharraz          #+#    #+#             */
/*   Updated: 2022/12/09 10:09:37 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parent.hpp"

void    Child::set_child()
{
	std::cin >> age;
}

void	Child::get_child()
{
	std::cout << age << std::endl;
}
