#if !defined(PARENT_HPP)
#define PARENT_HPP

// MACROS 

# include <iostream>
# include "Child.hpp"

class Parent
{
	private:
		Child child[2];
	public:
		void	set(int i);
		void	get(int i);
};

#endif // PARENT_HPP
