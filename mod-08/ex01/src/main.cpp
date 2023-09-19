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

#include "Span.hpp"

int main()
{

	Span mySpan = Span(4);

	mySpan.addNumber(std::numeric_limits<int>::min());
	mySpan.addNumber(std::numeric_limits<int>::max());
	std::cout << mySpan.longestSpan() << std::endl;
	std::cout << mySpan.shortestSpan() << std::endl;

	std::vector<int> myVector;
	myVector.push_back(14);
	myVector.push_back(32);

	mySpan.addNumbers(myVector.begin(), myVector.end());

	// for(unsigned int i = 0; i < myVector.size(); i++)
	// {
	// std::cout << "["<< i <<"] : " << myVector[i] << std::endl;
	// }
	// myVector(4);
	return(0);
}