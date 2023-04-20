/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:04:39 by leklund           #+#    #+#             */
/*   Updated: 2023/04/20 07:04:43 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point &to_copy_from);
	Fixed getX() const;
	Fixed getY() const;
	~Point();
};
bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif
