/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:09:05 by leklund           #+#    #+#             */
/*   Updated: 2023/04/22 11:09:07 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

int main()
{
	// {
	// 	std::cout << "==================================================" << std::endl;
	// 	AForm *Form1 = new PresidentialPardonForm();
	// 	// std::cout << Form1 << std::endl;

	// }
	{
		Bureaucrat *a = new Bureaucrat();
		AForm *b = new PresidentialPardonForm();
		// Form *c = new RobotomyRequestForm();
		// Form *d = new ShrubberyCreationForm();

		std::cout << "Testing" << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		delete a;
		delete b;
	}
	std::cout << "==================================================" << std::endl;
	return (0);
}
