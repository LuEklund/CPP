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
#define BIG 10001

int main()
{
	{
		std::cout << "=================[Simple SPAN MIN MAX EXAMPLE]==================" << std::endl;
		Span mySpan = Span(4);
		mySpan.addNumber(500);
		mySpan.addNumber(20);
		mySpan.addNumber(-1000);
		std::cout << "Largest DIFF " << mySpan.longestSpan() << std::endl;
		std::cout << "Smalest Diff " << mySpan.shortestSpan() << std::endl;
	}
	{
		std::cout << "=================[BIG]==================" << std::endl;
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
		std::cout << "=================[ZERO SIZE SPAN]==================" << std::endl;
		Span mySpan = Span(0);
		try
		{
			mySpan.addNumbers(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << "no size" << std::endl;;
		}
		try
		{
			std::cout << "Largest DIFF " << mySpan.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "No values" << std::endl;;
		}
	}
	{
		std::cout << "=================[SMALL SPAN]==================" << std::endl;
		Span mySpan = Span(4);
		mySpan.addNumbers(1);
		try
		{
			std::cout << "Smalest Diff " << mySpan.shortestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << "Cannot do the opperation" << std::endl;;
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