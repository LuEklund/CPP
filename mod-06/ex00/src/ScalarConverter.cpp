/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:57:40 by leklund           #+#    #+#             */
/*   Updated: 2023/08/18 09:57:41 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

Type ScalarConverter::_get_type(const std::string str)
{
	if(str.length() == 1)
	{
		if(isdigit(str[0]))
			return (INT);
		else
			return(CHAR);
	}
	else
	{
		if(!str.compare("nanf") || !str.compare("nan"))
			return(NOTANUMBER);
		if(!str.compare("+inff") || !str.compare("+inf"))
			return(INF);
		if(!str.compare("-inff") || !str.compare("-inf"))
			return(INFN);
		if(str.find(".") != str.npos)
		{
			if(str.find("f") != str.npos)
				return(FLOAT);
			else
				return(DOUBLE);
		}
		else
			return(INT);
	}
}

void	ScalarConverter::_intchar_out(int value)
{
	if(isprint(value))
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	else
	{
		if(value < 0 || value > 255)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << value << std::endl;
	
}

void	_floatdouble_out(double value)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void	ScalarConverter::_double_convert(std::string str)
{
	int value;
	double double_value;
	std::istringstream iss(str);
	iss >> double_value;
	value = static_cast<int>(std::floor(double_value));
	_intchar_out(value);
	_floatdouble_out(double_value);

}

void	ScalarConverter::convert(const std::string str)
{
	Type inType = _get_type(str);
	if(inType == INT)
	{
		_intchar_out(std::atoi(str.c_str()));
		_floatdouble_out(std::atoi(str.c_str()));
	}
	else if(inType == CHAR)
	{
		_intchar_out(str[0]);
		_floatdouble_out(str[0]);
	}
	else if(inType == FLOAT)
	{
		_double_convert(str.substr(0, str.length() - 1));
	}
	else if(inType == DOUBLE)
	{
		_double_convert(str);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if(inType == NOTANUMBER)
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		if(inType == INF)
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		if(inType == INFN)
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
}
