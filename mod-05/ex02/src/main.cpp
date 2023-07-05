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
	std::cout << "==================================================" << std::endl;
	{
		Bureaucrat *Steve = new Bureaucrat("Steve",1);
		std::cout << "----------------------------" << std::endl;
		AForm *PresidentalForm = new PresidentialPardonForm("Hive");
		Steve->executeForm(*PresidentalForm);
		Steve->signAForm(*PresidentalForm);
		Steve->executeForm(*PresidentalForm);
		Steve->executeForm(*PresidentalForm);
		std::cout << "----------------------------" << std::endl;
		AForm *RobotomyForm = new RobotomyRequestForm("42");
		Steve->signAForm(*RobotomyForm);
		Steve->executeForm(*RobotomyForm);
		std::cout << "----------------------------" << std::endl;
		AForm *ShrubberyForm = new ShrubberyCreationForm("Bocal");
		Steve->signAForm(*ShrubberyForm);
		Steve->executeForm(*ShrubberyForm);
		std::cout << "----------------------------" << std::endl;
		delete Steve;
		delete PresidentalForm;
		delete RobotomyForm;
		delete ShrubberyForm;
	}
	{
		std::cout << "==================================================" << std::endl;
		Bureaucrat *Incompetent = new Bureaucrat("Incompetent",150);
		std::cout << "----------------------------" << std::endl;
		AForm *PresidentalForm = new PresidentialPardonForm("Hive1");
		Incompetent->signAForm(*PresidentalForm);
		Incompetent->executeForm(*PresidentalForm);
		std::cout << "----------------------------" << std::endl;
		AForm *RobotomyForm = new RobotomyRequestForm("421");
		Incompetent->signAForm(*RobotomyForm);
		Incompetent->executeForm(*RobotomyForm);
		std::cout << "----------------------------" << std::endl;
		AForm *ShrubberyForm = new ShrubberyCreationForm("Bocal1");
		Incompetent->signAForm(*ShrubberyForm);
		Incompetent->executeForm(*ShrubberyForm);
		std::cout << "----------------------------" << std::endl;
		delete Incompetent;
		delete PresidentalForm;
		delete RobotomyForm;
		delete ShrubberyForm;
	}
	std::cout << "==================================================" << std::endl;
	return (0);
}
