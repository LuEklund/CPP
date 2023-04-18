/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkLine.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:28:24 by leklund           #+#    #+#             */
/*   Updated: 2023/04/17 09:28:25 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checkLine.hpp"
#include <fstream>

checkLine::checkLine(std::string fileName,
						std::string str_replace,
						std::string new_str,
						std::string newFilename):_fileName(fileName),_str_replace(str_replace), _new_str(new_str), _newFilename(newFilename)
{
	this->len = str_replace.length();
}

void	checkLine::write_line(std::string line, std::ofstream& newFile)
{
	int i = 0;
	while(line.length() && line[i] != '\0')
	{
		if(!strncmp(line.c_str() + i, _str_replace.c_str(), len))
		{
			i += len;
			newFile << _new_str;
		}
		else
		{
			newFile << line[i];
			i++;
		}
	}
	newFile << "\n";

}