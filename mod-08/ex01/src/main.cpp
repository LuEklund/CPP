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
	{
		std::cout << "=================[Simple SPAN MIN MAX EXAMPLE]==================" << std::endl;
		Span mySpan = Span(4);
		mySpan.addNumber(std::numeric_limits<int>::min());
		mySpan.addNumber(std::numeric_limits<int>::max());
		std::cout << "Largest DIFF" << mySpan.longestSpan() << std::endl;
		std::cout << "Smalest Diff" << mySpan.shortestSpan() << std::endl;
	}
	{
		std::cout << "=================[BIG]==================" << std::endl;
		#define BIG 10001
		Span mySpan = Span(BIG);
		mySpan.addNumbers(BIG-1);
		try
		{
			mySpan.addNumbers(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Went above limit" << std::endl;;
		}
	}
	{
		std::cout << "=================[PROJECT TEST]==================" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}



	return(0);
}