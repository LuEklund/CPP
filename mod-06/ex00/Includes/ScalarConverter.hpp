/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:57:30 by leklund           #+#    #+#             */
/*   Updated: 2023/08/18 09:57:31 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP 
# include <string>
# include <iostream>
# include <cctype>
# include <iomanip>
# include <sstream>
# include <cmath>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INF,
	INFN,
	NOTANUMBER
};

class ScalarConverter
{
private:
	static Type _get_type(const std::string str);
	static void	_intchar_out(int value);
	static void	_double_convert(std::string str);
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter &);
	~ScalarConverter();
	
public:
	static void	convert(const std::string str);
};


#endif
