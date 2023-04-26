/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkLine.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:27:42 by leklund           #+#    #+#             */
/*   Updated: 2023/04/17 09:27:44 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKLINE_HPP
# define CHECKLINE_HPP
# include <iostream>

class checkLine
{
private:
	std::string _fileName;
	std::string _str_replace;
	std::string _new_str;
	std::string _newFilename;
	std::string write_line(std::string& line);
public:
	checkLine(const std::string& fileName, const std::string& new_str, const std::string& str_replace);
	void processFile();

	// ~checkLine();
};



#endif