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
# include <list>

int main()
{
	{
		std::cout << "=================[MY MUTANTSTACK]==================" << std::endl;
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
	}
	{
		std::cout << "=================[NORMAL LIST]==================" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		std::cout << "added: 5" << std::endl; 
		mstack.push_back(17);
		std::cout << "added: 17" << std::endl; 
		std::cout << "TOP: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "pop()" << std::endl; 
		std::cout << "SIZE: "<< mstack.size() << std::endl;
		mstack.push_back(3);
		std::cout << "added: 3" << std::endl; 
		mstack.push_back(5);
		std::cout << "added: 5" << std::endl; 
		mstack.push_back(737);
		std::cout << "added: 737" << std::endl; 
		mstack.push_back(0);
		std::cout << "added: 0" << std::endl; 
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Iterating" << std::endl; 
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}