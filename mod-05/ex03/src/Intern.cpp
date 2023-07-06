/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:13:37 by leklund           #+#    #+#             */
/*   Updated: 2023/07/05 16:13:38 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"
# include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "+Const: Intern" << std::endl;
	formCreators[2] = &Intern::createPresidentialPardonForm;
	formCreators[1] = &Intern::createRobotomyRequestForm;
	formCreators[0] = &Intern::createShrubberyCreationForm;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "+copyConst: Intern" << std::endl;
	this->formCreators[0] = copy.formCreators[0];
	this->formCreators[1] = copy.formCreators[1];
	this->formCreators[2] = copy.formCreators[2];
}

Intern& Intern::operator=(const Intern& copy)
{
	std::cout << "+copyAsign: Intern" << std::endl;
	if(this == &copy)
		return(*this);
	return(*this);
}

Intern::~Intern()
{
	std::cout << "-deConst: Intern" << std::endl;
}

AForm* Intern::makeForm(std::string FormType, std::string target)
{
	std::string	_levels[] = {"robotomy request", "shruberry request", "presidental request"};
	int i = 0;
	while(i < 3)
	{
		if(_levels[i] == FormType)
		{
			std::cout << "Intern creates " << FormType << std::endl;
			return((this->*formCreators[i])(target));
		}
		i++;
	}
	std::cout << "Error could not create " << FormType << std::endl;
	return NULL;
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}