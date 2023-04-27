/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 06:32:23 by leklund           #+#    #+#             */
/*   Updated: 2023/04/18 06:32:26 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"
#include <iostream>

Harl::~Harl()
{
}

Harl::Harl()
{
	_functions[0] = &Harl::debug;
	_functions[1] = &Harl::info;
	_functions[2] = &Harl::warning;
	_functions[3] = &Harl::error;
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level )
{
	std::string	_levels[] = {"debug", "info", "warning", "error"};
	int i = 0;
	while(i < 4)
	{
		if(_levels[i] == level)
			break ;
		i++;
	}
	switch(i)
	{
		case 0:
			(this->*_functions[0])();
			(this->*_functions[1])();
			(this->*_functions[2])();
			(this->*_functions[3])();
		 break;
		case 1:
			(this->*_functions[1])();
			(this->*_functions[2])();
			(this->*_functions[3])();

		 break;
		case 2:
			(this->*_functions[2])();
			(this->*_functions[3])();
		 break;
		case 3:
			(this->*_functions[3])();
		 break;
		default:
			std::cout << "Invalid level: " << level << std::endl;
		 break;
	}
}
