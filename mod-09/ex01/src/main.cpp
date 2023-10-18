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

#include "RPN.hpp"
//	# Your program must take an inverted Polish mathematical expression as an argument.
//	# Two arguments only
//	# only digets accepts and opperators + - / *
//	# output on the standar output with the correct result
//	# error => standar output
//	# use stack
//	# can ignore decimals and brackets
//	# overflow protect
//	# devision by 0 protect


//=======================
//OVERFLOW protection shorter if cast and calcuate to bigger data type?
//=======================


int main(int argc, char **argv)
{
	if(argc == 2)
	{
		RPN	myRPN;
		switch(myRPN.calculate(argv[1]))
		{
			case NO_SPACE:
				std::cout << "ERROR: Invalid formating" << std::endl;
				return(-1);
			case INVALID_CHAR:
				std::cout << "ERROR: Invalid character" << std::endl;
				return(-1);
			case INSUFFICIENT_VALUES:
				std::cout << "ERROR: Not enough values in stack to do opperation" << std::endl;
				return(-1);
			case INVALID_END:
				std::cout << "ERROR: Can not end like this" << std::endl;
				return(-1);
			case DIVISION_BY_ZERO:
				std::cout << "ERROR: Devision by zero prevented" << std::endl;
				return(-1);
			case OVERFLOW:
				std::cout << "ERROR: Overflow Caught" << std::endl;
				return(-1);
		}
	}
	else
	{
		std::cout << "invalid amount of agruments" << std::endl;
		return(-1);
	}
	return(0);
}