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
	{
		std::cout << "==================================================" << std::endl;
		Bureaucrat Peter("Peter", 1);
		Form Form1("Form1",1211,12);
		// Peter.signForm(Form1);
		// Peter.signForm(Form1);
		// try
		// {
		// 	low.DecrementGrade();
		// 	low.DecrementGrade();
		// }
		// catch(Bureaucrat::GradeTooLowException& e)
		// {
		// 	std::cout << "cannot Decrement grade" << std::endl;
		// }
	}
	std::cout << "==================================================" << std::endl;
	return (0);
}