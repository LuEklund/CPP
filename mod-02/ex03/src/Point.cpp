/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:04:34 by leklund           #+#    #+#             */
/*   Updated: 2023/04/20 07:04:36 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
}

Point::Point(const Point &to_copy_from) : _x(to_copy_from._x), _y(to_copy_from._y)
{
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		(Fixed) _x = other.getX();
		(Fixed) _y = other.getY();
	}
	return (*this);
}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

Point::~Point()
{
}
