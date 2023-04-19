/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:18:09 by leklund           #+#    #+#             */
/*   Updated: 2023/04/18 10:18:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int					fixed_point;
	static const int	bit;
public:
	Fixed();

	Fixed(const int value);
	Fixed(const float floater);

	Fixed(const Fixed &to_copy_from);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	friend std::ostream& operator<<(std::ostream& outPut, const Fixed& fixed_class);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};





#endif
