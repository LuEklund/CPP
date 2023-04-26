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
		|| !argv[1] || !argv[1][0]
		|| !argv[2] || !argv[2][0]
		|| !argv[3] || !argv[3][0])
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	checkLine checkTheLine(argv[1], argv[2] ,argv[3]);
	checkTheLine.processFile();

	return(0);
}