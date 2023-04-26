/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:07:53 by leklund           #+#    #+#             */
/*   Updated: 2023/04/12 11:07:55 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	display_zero(int value)
{
	if(value < 10)
    	std::cout << "0";
}

int		Account::checkAmount( void ) const
{
	return(_amount);
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900);
	display_zero(now->tm_mon);
	std::cout << (now->tm_mon + 1);
	display_zero(now->tm_mday);
    std::cout << (now->tm_mday) << "_";
	display_zero(now->tm_hour);
	std::cout << (now->tm_hour);
	display_zero(now->tm_min);
	std::cout << (now->tm_min);
	display_zero(now->tm_sec);
	std::cout << (now->tm_sec) << "] ";
	
}

int	Account::getNbAccounts( void ){return(Account::_nbAccounts);}
int	Account::getTotalAmount( void ){return(Account::_totalAmount);}
int	Account::getNbDeposits( void ){return(Account::_totalNbDeposits);}
int	Account::getNbWithdrawals( void ){return(Account::_totalNbWithdrawals);}

void	Account::makeDeposit( int deposit )
{
	if(deposit > 0)
	{
		_nbDeposits++;
		Account::_totalNbDeposits++;
		_amount += deposit;
		Account::_totalAmount += deposit;
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount - deposit
	<< ";deposit:" << deposit
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits 
	<< std::endl;
	
}
Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = getNbAccounts();
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount 
				<< ";created"
				<< std::endl;
}
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount 
				<< ";closed"
				<< std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if(withdrawal > 0 && _amount >= withdrawal)
	{
		_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount + withdrawal
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals 
		<< std::endl;
		return (1);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount 
		<< ";withdrawal:refused" 
		<< std::endl;
		return (0);
	}
	
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount 
				<< ";deposits:" << _nbDeposits 
				<< ";withdrawals:" << _nbWithdrawals 
				<< std::endl;
}
