/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 06:32:13 by leklund           #+#    #+#             */
/*   Updated: 2023/04/18 06:32:14 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "invalid params" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}
