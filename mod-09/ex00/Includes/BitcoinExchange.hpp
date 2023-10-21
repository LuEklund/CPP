/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:23:54 by leklund           #+#    #+#             */
/*   Updated: 2023/10/11 16:23:56 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <climits>

enum	ERRORS
{
	OK,
	FILE_FAIL,
	INVALID_HEADER,
	EMPTY_DATABASE,
	INVALID_YEAR,
	INVALID_MONTH,
	IMVALID_DAY,
	IMVALID_VALUE,
	INSERTION_ERROR,
	IMPOSSIBLE

};

typedef std::map < unsigned int, std::map<unsigned int, std::map<unsigned int, float > > > year;
typedef std::map < unsigned int, std::map<unsigned int, float > > month;
typedef std::map < unsigned int, float > day;

class BitcoinExchange
{
private:
	
	year	database;
	int		minYear;
	int		minMonth;
	int		minDay;

	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);

	float	ft_stof(std::string value);
	int		ft_stoi(std::string value);

	int		validMonth(std::string month);
	int		validDay(std::string day, int year, int month);

	int		insertIntoDatabase(std::string line);

	float	findValidDay(day daysInMonth, int day);
	float	findValidMonthDay(month monthsInYear, int month, int day);
	float	thisDateValue(int year, int month, int day);
	int		lineOut(std::string line);
public:
	BitcoinExchange();
	~BitcoinExchange();

	int		readDatabaseFile();
	int		readInputFile(std::string file);
};





#endif
