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

#include "PmergeMe.hpp"
//	# invalid input check
//	# store in positive integer conatiner
//	# sort and calculate time
//	# display time


int main(int argc, char **argv)
{
	if(argc > 1)
	{
		PmergeMe	MyPmergeMe;
		if(MyPmergeMe.saveValidInput(argc, argv) != OK)
		{
			std::cout << "ERROR: invalid Input" << std::endl;
			return(-1);
		}
		MyPmergeMe.action();
	}
	else
	{
		std::cout << "invalid amount of agruments" << std::endl;
		return(-1);
	}
	return(0);
}