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
#include <cmath>

Fixed::Fixed()
{
	this->fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : fixed_point(integer << bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floater) : fixed_point(std::roundf(floater * (1 << bit)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy_from)
{
	this->fixed_point = to_copy_from.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_point = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->fixed_point > other.fixed_point);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->fixed_point < other.fixed_point);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->fixed_point >= other.fixed_point);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->fixed_point <= other.fixed_point);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->fixed_point == other.fixed_point);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->fixed_point != other.fixed_point);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed Fixed::operator++()
{
    this->fixed_point += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed Fixed::operator--()
{
    this->fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    operator--();
    return temp;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt( void ) const
{
	return (fixed_point >> 8);
}

float Fixed::toFloat( void ) const
{
	return ((float)fixed_point / (1 << bit));
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(fixed_point);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

void Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}

std::ostream& operator<<(std::ostream& outPut, const Fixed& fixed_class)
{
	outPut << fixed_class.toFloat();
	return (outPut);
}

const int	Fixed::bit = 8;
