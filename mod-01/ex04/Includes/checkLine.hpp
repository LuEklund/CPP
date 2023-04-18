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
	int	len;

public:
	checkLine(std::string fileName, std::string new_str, std::string str_replace, std::string newFilename);
	void	write_line(std::string line, std::ofstream&	newFile);
	// ~checkLine();
};



#endif