/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 06:42:25 by leklund           #+#    #+#             */
/*   Updated: 2023/08/20 06:42:26 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
}

Base * generate(void)
{
	std::srand(std::time(NULL));
	int val = std::rand() % (3);
	std::cout << val << std::endl;
	if(val)
	{
		if(val == 1)
			return(new B);
		else
			return(new C);
	}
	return(new A);
}

void identify(Base* p)
{
	if(dynamic_cast<A *>(p))
		std::cout << "*is A" << std::endl;
	else if(dynamic_cast<B *>(p))
		std::cout << "*is B" << std::endl;
	else
		std::cout << "*is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A &>(p);
		std::cout << "&is A" << std::endl;
		static_cast<void>(a);
	}
	catch(std::bad_cast&)
	{
		try
		{
			B& b = dynamic_cast<B &>(p);
			std::cout << "&is B" << std::endl;
			static_cast<void>(b);
		}
		catch(std::bad_cast&)
		{
			std::cout << "&is C" << std::endl;
		}
	}
}