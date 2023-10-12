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

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
	{

		BitcoinExchange myExchange;

		switch(myExchange.readDatabaseFile())
		{
			case FILE_FAIL:
				std::cout << "ERROR: Database failed to read file" << std::endl;
				return(-1);
			case INVALID_HEADER:
				std::cout << "ERROR: Database invalid header section" << std::endl;
				return(-1);
			case EMPTY_DATABASE:
				std::cout << "ERROR: Database no data" << std::endl;
				return(-1);
			case INSERTION_ERROR:
				std::cout << "ERROR: Database invalid line, exiting..." << std::endl;
				return(-1);
		}
		switch(myExchange.readInputFile(argv[1]))
		{
			case FILE_FAIL:
				std::cout << "ERROR: inputFile failed to read file" << std::endl;
				return(-1);
			case INVALID_HEADER:
				std::cout << "ERROR: inputFile invalid header section" << std::endl;
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