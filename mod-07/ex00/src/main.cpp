/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:09:09 by leklund           #+#    #+#             */
/*   Updated: 2023/08/18 10:09:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	{
		std::cout << "==================================================" << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "==================================================" << std::endl;
		int a = 1;
		int b = 2;
		std::cout << a << " | " << b << std::endl;
		swap(a,b);
		std::cout << a << " | " << b << std::endl;
		std::cout << "min: " << min(a,b) << std::endl;
		std::cout << "max: " << max(a,b) << std::endl;
	}
	{
		std::cout << "==================================================" << std::endl;
		char a = 'a';
		char b = 'b';
		std::cout << a << " | " << b << std::endl;
		swap(a,b);
		std::cout << a << " | " << b << std::endl;
		std::cout << "min: " << min(a,b) << std::endl;
		std::cout << "max: " << max(a,b) << std::endl;
	}
	return(0);
}