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