/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 07:49:22 by leklund           #+#    #+#             */
/*   Updated: 2023/04/17 07:49:24 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fstream>
#include <string>
#include "checkLine.hpp"

int	main(int argc, char **argv)
{
	if(argc != 4
		|| !argv[0] || !argv[0][0]
		|| !argv[1] || !argv[1][0]
		|| !argv[2] || !argv[2][0]
		|| !argv[3] || !argv[3][0])
	{
		std::cout << "Invalid params" << std::endl;
		return (1);
	}
	std::string line;
	std::string	fileName = argv[1];
	std::string	newFilename  = fileName + ".replace";
	std::ofstream	newFile(newFilename);
	if(!newFile.is_open())
	{
		std::cout << "file culd not be created" << std::endl;
		return (1);
	}

	std::ifstream file(fileName);
	if(!file.is_open())
	{
		std::cout << "file culd not be opened" << std::endl;
		newFile.close();
		return (1);
	}

	checkLine checkTheLine(fileName, argv[2] ,argv[3], newFilename);
	while(std::getline(file, line))
	{
		//DO YOU ALLWAYS NEED NEWLINE?????
		checkTheLine.write_line(line, newFile);
	}

	file.close();
	newFile.close();
	return(0);
}