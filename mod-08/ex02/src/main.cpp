/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:09:09 by leklund           #+#    #+#             */
/*   Updated: 2023/08/18 10:09:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	std::cout << "added: 5" << std::endl; 
	mstack.push(17);
	std::cout << "added: 17" << std::endl; 
	std::cout << "TOP: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "pop()" << std::endl; 
	std::cout << "SIZE: "<< mstack.size() << std::endl;
	mstack.push(3);
	std::cout << "added: 3" << std::endl; 
	mstack.push(5);
	std::cout << "added: 5" << std::endl; 
	mstack.push(737);
	std::cout << "added: 737" << std::endl; 
	mstack.push(0);
	std::cout << "added: 0" << std::endl; 
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Iterating" << std::endl; 
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << "done Iterating" << std::endl; 
	std::stack<int> s(mstack);
	s.c.begin();
	return (0);
}