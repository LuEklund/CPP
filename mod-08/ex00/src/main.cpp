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

#include "easyfind.hpp"

int main()
{
	{
		std::vector<int> myVector;
		myVector.push_back(1);
		myVector.push_back(2);
		myVector.push_back(3);
		myVector.push_back(4);
		myVector.push_back(5);
		try
		{
			std::vector<int>::iterator it = easyfind(myVector,3);
			std::cout << "FOUND it " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "number not found" << std::endl;
		}
		try
		{
			std::vector<int>::iterator it = easyfind(myVector,-3);
			std::cout << "FOUND it " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "number not found" << std::endl;
		}
	}
	{
		std::list<char> myList;
		myList.push_back('a');
		myList.push_back('b');
		myList.push_back('c');
		myList.push_back('d');
		myList.push_back('e');
		try
		{
			std::list<char>::iterator it = easyfind(myList,'e');
			std::cout << "FOUND it " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "number not found" << std::endl;
		}
		try
		{
			std::list<char>::iterator it = easyfind(myList,'f');
			std::cout << "FOUND it " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "number not found" << std::endl;
		}

	}
	return(0);
}