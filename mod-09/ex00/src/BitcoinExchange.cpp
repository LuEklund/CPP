/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:24:05 by leklund           #+#    #+#             */
/*   Updated: 2023/10/11 16:24:07 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

// month < 8 && month%2 != 0 (31 days)
// month >= 8 && month%2 == 0 (31 days)
// reset has 30 days except for febuary
// leaps years feb 29 day (yeas%4 = 0 && (years%100 != 0 || years%400 == 0 )) is leep years (feb has 28 days)

//if cant read or find data.csv exist with error. (can hard code)
//if cant find or read input file axit. (have to be adjusted to file input n hardcode)

BitcoinExchange::BitcoinExchange()
{
};

BitcoinExchange::~BitcoinExchange()
{
};

float	BitcoinExchange::ft_stof(std::string value)
{
	std::stringstream	ss;
	bool				dot = false;
	float				res;
	unsigned int		len = value.length();

	for(size_t i = 0; i < len; i++)
	{
		if(!isdigit(value[i]))
		{
			if(value[i] == '.' && dot == false)
				dot = true;
			else
				return(-1);
		}
	}
	ss.str(value);
	ss >> res;
	if (ss.fail() == true)
		return (-1);
	if(res >= std::numeric_limits<int>::max())
		return (-1);
	return(res);
}

int	BitcoinExchange::validMonth(std::string month)
{
	int	monthInt = static_cast<int>(ft_stof(month));
	if(monthInt > 12)
		return (-1);
	else
		return (monthInt);
};

int	BitcoinExchange::validDay(std::string day, int year, int month)
{
	int	dayInt = static_cast<int>(ft_stof(day));
		// std::cout << "[CHECKING]\n" << "[" << year << "]" << "[" << month << "]" << "[" << dayInt << "]" << std::endl;
	if((month < 8 && month%2 != 0) || (month >= 8 && month%2 == 0))
	{
		if(dayInt > 31)
		{
			// std::cout << "to big day for month 31" << std::endl;
			return (-1);
		}
	}
	else
	{
		if(month == 2)
		{
			if(year%4 == 0 && (year%100 != 0 || year%400 == 0))
			{
				if(dayInt > 29)
				{
					// std::cout << "to big dayInt for leap year" << std::endl;
					return (-1);
				}
			}
			else if (dayInt > 28)
			{
				// std::cout << "to big day for feb" << std::endl;
				return (-1);
			}
		}
		else if(dayInt > 30)
		{
			// std::cout << "to big dayInt for month 30" << std::endl;
			return (-1);
		}
	}
	
	return(dayInt);
};



int	BitcoinExchange::insertIntoDatabase(std::string line)
{
	unsigned int	len = line.length();
	unsigned int	i = 0;
	std::string		yearStr, monthStr, dayStr, valueStr;
	int				yearInt, monthInt, dayInt;
	float			valueFloat;


	while(i < len && line[i] != '-')
	{
		yearStr += line[i];
		i++;
	}
	if((yearInt = static_cast<int>(ft_stof(yearStr))) < 0)
		return (1);
	i++;

	while(i < len && line[i] != '-')
	{
		monthStr += line[i];
		i++;
	}
	if((monthInt = validMonth(monthStr)) < 0)
		return (2);
	i++;

	while(i < len && line[i] != ',')
	{
		dayStr += line[i];
		i++;
	}
	if((dayInt = validDay(dayStr, yearInt, monthInt)) < 0)
		return (3);
	i++;

	while(i < len)
	{
		valueStr += line[i];
		i++;
	}
	valueFloat = ft_stof(valueStr);
	if(valueFloat < 0)
		return (4);
	database[yearInt][monthInt][dayInt] = valueFloat;
	return (0);

};

int	BitcoinExchange::readDatabaseFile()
{
	std::ifstream file("data.csv");
	if(file.bad() || file.fail())
		return (-1);
	unsigned	int rowNum = 1;
	std::string line;
	std::getline(file,line);
	if(line != "date,exchange_rate")
	{
		file.close();
		std::cerr << "Database: invalid header section" << std::endl;
		return (-1);
	}
	while(std::getline(file,line))
	{
		rowNum++;
		if(insertIntoDatabase(line))
			std::cerr << "Database invalid line: " << rowNum << std::endl;
	}
	file.close();
	return(0);
};


// int	BitcoinExchange::findValidDay(int year, int month, int day)
// {
// 	while(day > 0)
// 	{

// 	}
// };

// int	BitcoinExchange::findValidMonth(int year, int month, int day)
// {
// 	while(month > 0)
// 	{
// 		findValidDay
// 	}
// };

int	BitcoinExchange::thisDateValue(int year, int month, int day)
{
	// while(year > 0)
	// {
	// 	findValidMonth
	// }
	int	value = year + month + day;
	(void) value;
	// if(database.find(year)->second.find(month)->second.find(day) != database.find(year)->second.find(month)->second.end())
	// 	return(database.find(year)->second.find(month)->second.find(day)->second);
	return(2);
};

int	BitcoinExchange::lineOut(std::string line)
{
	unsigned int	len = line.length();
	unsigned int	i = 0;
	std::string		yearStr, monthStr, dayStr, valueStr;
	int				yearInt, monthInt, dayInt;
	float			amountFloat;


	while(i < len && line[i] != '-')
	{
		yearStr += line[i];
		i++;
	}
	if((yearInt = static_cast<int>(ft_stof(yearStr))) < 0)
		return (1);
	i++;

	while(i < len && line[i] != '-')
	{
		monthStr += line[i];
		i++;
	}
	if((monthInt = validMonth(monthStr)) < 0)
		return (2);
	i++;

	while(i < len && line[i] != '|')
	{
		if(line[i] != ' ')
			dayStr += line[i];
		i++;
	}
	if((dayInt = validDay(dayStr, yearInt, monthInt)) < 0)
		return (3);
	i++;

	while(i < len)
	{
		if(line[i] != ' ')
			valueStr += line[i];
		i++;
	}
	amountFloat = ft_stof(valueStr);
	if(amountFloat < 0)
		return (4);
	std::cout << amountFloat << std::endl;
	std::cout << yearInt << "-" << monthInt << "-" << dayInt << " =>" << amountFloat << " = " \
	<< (amountFloat * thisDateValue(yearInt, monthInt, dayInt)) << std::endl;
	return (0);

};

int		BitcoinExchange::readInputFile(std::string filename)
{
	std:: ifstream file(filename);
	if(file.bad() || file.fail())
		return (-1);
	unsigned	int rowNum = 1;
	std::string line;
	std::getline(file,line);
	if(line != "date | value")
	{
		file.close();
		std::cerr << "inputFile: invalid header section" << std::endl;
		return (-1);
	}
	while(std::getline(file,line))
	{
		rowNum++;
		if(lineOut(line))
			std::cerr << "inputFile invalid line: " << rowNum << std::endl;
	}
	file.close();
	return(0);
};

