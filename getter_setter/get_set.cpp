/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:04:16 by akharraz          #+#    #+#             */
/*   Updated: 2022/12/09 03:06:25 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_set.hpp"

void	GetSet::set()
{
    std::cin >> name;
}

std::string	GetSet::get()
{
	return name;
}

int main()
{
    GetSet getset[2];

    getset[0].set();
    std::cout << getset[0].get() << std::endl;    
    return (0);
}