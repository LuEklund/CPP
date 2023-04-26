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

checkLine::checkLine(const std::string& fileName,
						const std::string& str_replace,
						const std::string& new_str):_fileName(fileName),_str_replace(str_replace), _new_str(new_str), _newFilename(fileName + ".replace"){}

void checkLine::processFile()
{
	std::ifstream inputFile(_fileName);
	std::ofstream outputFile(_newFilename);

	if (!inputFile.is_open()) {
		std::cerr << "Error opening input file: " << _fileName << std::endl;
		return;
	}
	if (!outputFile.is_open()) {
		std::cerr << "Error opening output file: " << _newFilename << std::endl;
		inputFile.close();
		return;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		outputFile << write_line(line) << std::endl;
	}

	inputFile.close();
	outputFile.close();
}

std::string checkLine::write_line(std::string& line)
{
	std::string result;
        size_t pos = 0, lastPos = 0;

        while ((pos = line.find(_str_replace, lastPos)) != std::string::npos) {
            result += line.substr(lastPos, pos - lastPos);
            result += _new_str;
            lastPos = pos + _str_replace.length();
        }
        result += line.substr(lastPos);

        return result;

}