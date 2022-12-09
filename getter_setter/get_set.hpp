/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:19:37 by akharraz          #+#    #+#             */
/*   Updated: 2022/12/09 00:53:55 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GET_SET_HPP)
#define GET_SET_HPP

# include <iostream>

class GetSet
{
	private:
		int 		data;
		std::string	name;
	public:
		void		set();
		std::string	get();
};

#endif // GET_SET_HPP
