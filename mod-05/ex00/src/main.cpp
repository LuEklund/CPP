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
		Bureaucrat low("low", 150);
		low.IncrementGrade();
		try
		{
			low.DecrementGrade();
			low.DecrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << "cannot Decrement grade" << std::endl;
		}
		Bureaucrat high("high", 1);
		high.DecrementGrade();
		try
		{
			high.IncrementGrade();
			high.IncrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "cannot Increment grade" << std::endl;
		}
	}
	{
		std::cout << "==================================================" << std::endl;
		try
		{
			Bureaucrat low("low", 151);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << "init grade too low" << std::endl;
		}
		try
		{
			Bureaucrat high("high", 0);
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "init grade too high" << std::endl;
		}
	}
	{
		std::cout << "==================================================" << std::endl;
		Bureaucrat Bob("Bob", 42);
		Bob.IncrementGrade();
		Bureaucrat Bob2(Bob);
		Bob2.DecrementGrade();
		Bob2.DecrementGrade();
		Bob2.DecrementGrade();
		Bob2.DecrementGrade();
		Bureaucrat Will("Will", 69);
		Will.IncrementGrade();
		Will.IncrementGrade();
		Will.IncrementGrade();
		Will.IncrementGrade();
		Will.IncrementGrade();
		Will.IncrementGrade();
		Will.IncrementGrade();
		Will.IncrementGrade();
		Will = Bob2;
		std::cout << Will << std::endl;
	}
	std::cout << "==================================================" << std::endl;
	return (0);
}