/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:18:01 by leklund           #+#    #+#             */
/*   Updated: 2023/04/18 10:18:03 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"
#include <iostream>
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed()
{
	this->fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed &to_copy_from)
{
	this->fixed_point = to_copy_from.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return (*this);
	fixed_point = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(fixed_point);
}
void Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}
const int	Fixed::bit = 8;
