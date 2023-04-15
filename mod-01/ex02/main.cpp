/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:05:59 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 10:06:01 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int	main()
{
	std::string myString = "HI THIS IS BRAIN";
	std::string* stringPTR = &myString;
	std::string& stringREF = myString;

	std::cout << &myString << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << myString << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}

// 0x7ffeee1277c0 norm
// 0x7ffeee1277b8 *
// 0x7ffeee1277c0 &

// HI THIS IS BRAIN
// 0x7ffeee1277c0
// HI THIS IS BRAIN
