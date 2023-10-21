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

BitcoinExchange::BitcoinExchange() : minYear(INT_MAX), minMonth(INT_MAX), minDay(INT_MAX)
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
	return(res);
}

int	BitcoinExchange::ft_stoi(std::string value)
{
	std::stringstream	ss;
	unsigned int		res;
	unsigned int		len = value.length();

	if (len > 10)
		return (-1);
	for(size_t i = 0; i < len; i++)
	{
		if(!isdigit(value[i]))
			return(-1);
	}
	ss.str(value);
	ss >> res;
	if (ss.fail() == true)
		return (-1);
	return(res);
}

int	BitcoinExchange::validMonth(std::string month)
{
	int	monthInt = ft_stoi(month);
	if(monthInt > 12)
		return (-1);
	else
		return (monthInt);
};

int	BitcoinExchange::validDay(std::string day, int year, int month)
{
	int	dayInt = ft_stoi(day);
	if((month < 8 && month%2 != 0) || (month >= 8 && month%2 == 0))
	{
		if(dayInt > 31)
			return (-1);
	}
	else
	{
		if(month == 2)
		{
			if(year%4 == 0 && (year%100 != 0 || year%400 == 0))
			{
				if(dayInt > 29)
					return (-1);
			}
			else if (dayInt > 28)
				return (-1);
		}
		else if(dayInt > 30)
			return (-1);
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
	if(yearStr.length() > 4 || (yearInt = ft_stoi(yearStr)) < 0 || yearInt > 2023)
		return (INVALID_YEAR);
	i++;

	while(i < len && line[i] != '-')
	{
		monthStr += line[i];
		i++;
	}
	if(monthStr.length() > 2 || (monthInt = validMonth(monthStr)) < 0 || monthInt == 0)
		return (INVALID_MONTH);
	i++;

	while(i < len && line[i] != ',')
	{
		dayStr += line[i];
		i++;
	}
	if(dayStr.length() > 2 || (dayInt = validDay(dayStr, yearInt, monthInt)) < 0 || dayInt == 0)
		return (IMVALID_DAY);
	i++;

	while(i < len)
	{
		valueStr += line[i];
		i++;
	}
	valueFloat = ft_stof(valueStr);
	if(valueFloat < 0)
		return (IMVALID_VALUE);
	if(yearInt <= minYear && monthInt <= minMonth && dayInt <= minDay)
	{
		minYear = yearInt;
		minMonth = monthInt;
		minDay = dayInt;
	}
	database[yearInt][monthInt][dayInt] = valueFloat;
	return (OK);

};

int	BitcoinExchange::readDatabaseFile()
{
	unsigned		int rowNum = 1;
	std::string		line;
	std::ifstream	file("data.csv");
	if(file.bad() || file.fail())
		return (FILE_FAIL);
	std::getline(file,line);
	if(line != "date,exchange_rate")
	{
		file.close();
		return (INVALID_HEADER);
	}
	while(std::getline(file,line))
	{
		rowNum++;
		if(insertIntoDatabase(line))
		{
			std::cout << "Database invalid line: " << rowNum << std::endl;
			return(INSERTION_ERROR);
		}
	}
	file.close();
	if(database.empty())
		return (EMPTY_DATABASE);
	return(OK);
};


float	BitcoinExchange::findValidDay(day daysInMonth, int dayInt)
{
	while(dayInt > 0)
	{
		if(daysInMonth.find(dayInt) != daysInMonth.end())
			return(daysInMonth.find(dayInt)->second);
		dayInt--;
	}
	return(0);
};

float	BitcoinExchange::findValidMonthDay(month monthsInYear, int monthInt, int dayInt)
{
	float	value;
	while(monthInt > 0)
	{
		if(monthsInYear.find(monthInt) != monthsInYear.end())
		{
			value = findValidDay(monthsInYear.find(monthInt)->second, dayInt);
			if (value)
				return(value);
		}
		dayInt = 31;
		monthInt--;
	}
	return(0);
};

float	BitcoinExchange::thisDateValue(int yearInt, int monthInt, int dayInt)
{
	float	value;
	while(yearInt >= minYear)
	{
		if(database.find(yearInt) != database.end())
		{
			value = findValidMonthDay(database.find(yearInt)->second, monthInt, dayInt);
			if (value)
				return(value);
		}
		monthInt = 12;
		dayInt = 31;
		yearInt--;
	}
	return(-1);
};

int	BitcoinExchange::lineOut(std::string line)
{
	unsigned int	len = line.length();
	unsigned int	i = 0;
	std::string		yearStr, monthStr, dayStr, valueStr;
	int				yearInt, monthInt, dayInt;
	float			amountFloat, value;


	while(i < len && line[i] != '-')
	{
		yearStr += line[i];
		i++;
	}
	if(yearStr.length() > 4 ||  (yearInt = ft_stoi(yearStr)) < 0 || yearInt > 2023)
		return (INVALID_YEAR);
	i++;

	while(i < len && line[i] != '-')
	{
		monthStr += line[i];
		i++;
	}
	if(monthStr.length() > 2 || (monthInt = validMonth(monthStr)) < 0 || monthInt == 0)
		return (INVALID_MONTH);
	i++;

	while(i < len)
	{
		if (line[i] == ' ' && i+1 < len && line[i+1] == '|')
		{
			i++;
			break ;
		}
		dayStr += line[i];
		i++;
	}
	if(dayStr.length() > 2 || (dayInt = validDay(dayStr, yearInt, monthInt)) < 0 || dayInt == 0)
		return (IMVALID_DAY);
	i++;

	if(line[i] != ' ')
		return (IMVALID_VALUE);
	i++;
	while(i < len)
	{
		valueStr += line[i];
		i++;
	}
	amountFloat = ft_stof(valueStr);
	if(amountFloat < 0 || amountFloat > 1000)
		return (IMVALID_VALUE);
	if((value = thisDateValue(yearInt, monthInt, dayInt)) < 0)
		return(IMPOSSIBLE);
	std::cout << yearInt << "-" << monthInt << "-" << dayInt << " => " << amountFloat << " = " \
	<< (amountFloat * value) << std::endl;
	return (OK);
};

int		BitcoinExchange::readInputFile(std::string filename)
{
	std::string		line;
	unsigned int	rowNum = 1;
	std::ifstream	file(filename.c_str());
	if(file.bad() || file.fail())
		return (FILE_FAIL);
	std::getline(file,line);
	if(line != "date | value")
	{
		file.close();
		return (INVALID_HEADER);
	}
	while(std::getline(file,line))
	{
		rowNum++;
		switch (lineOut(line))
		{
			case INVALID_YEAR:
				std::cout << "ERROR: inputFile on line [" << rowNum << "] invalid year field: " << line << std::endl;
				break;
			case INVALID_MONTH:
				std::cout << "ERROR: inputFile on line [" << rowNum << "] invalid month field: " << line  << std::endl;
				break;
			case IMVALID_DAY:
				std::cout << "ERROR: inputFile on line [" << rowNum << "] invalid day field: " << line  << std::endl;
				break;
			case IMVALID_VALUE:
				std::cout << "ERROR: inputFile on line [" << rowNum << "] invalid value field: " << line  << std::endl;
				break;
			case IMPOSSIBLE:
			std::cout << "ERROR: inputFile on line [" << rowNum << "] We dont have data this far back: " << line  << std::endl;
				break;
			default:
				break;
		}
	}
	file.close();
	return(OK);
};
