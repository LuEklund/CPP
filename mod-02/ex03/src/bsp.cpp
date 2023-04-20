/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:04:46 by leklund           #+#    #+#             */
/*   Updated: 2023/04/20 07:04:48 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

static Fixed	absolute(Fixed toCheck)
{
	if(toCheck < 0)
		return(toCheck * -1);
	return(toCheck);
}

static bool onSegment(Point const a, Point const b, Point const c)
{
	if(a.getX() <= Fixed::max(b.getX(),c.getX())
		&& a.getX() >= Fixed::min(b.getX(),c.getX())
		&& a.getY() <= Fixed::max(b.getY(),c.getY())
		&& a.getY() >= Fixed::max(b.getY(),c.getY()))
		return (true);
	return (false);
}

static Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed area;

	area = ((a.getX()*(b.getY() - c.getY())) + (b.getX()*(c.getY() - a.getY())) + (c.getX()*(a.getY() - b.getY())))/2;
	if (area == 0 && onSegment(a, b, c))
		return Fixed(-1);
	return (absolute(area));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{


	Fixed area1 = area(point, a, b);
	Fixed area2 = area(point, a, c);
	Fixed area3 = area(point, b, c);
	Fixed area4 = area(a, b, c);
	if(area1 == -1 || area2 == - 1 || area3 == -1 || area4 == -1)
		return(false);
	std::cout << "area1: " << area1 << std::endl;
	std::cout << "area2: " << area2 << std::endl;
	std::cout << "area3: " << area3 << std::endl;
	std::cout << "area4: " << area4 << std::endl;

	return (area1 + area2 + area3 == area4);

}


