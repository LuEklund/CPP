/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:27:30 by leklund           #+#    #+#             */
/*   Updated: 2023/07/04 07:27:31 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation",145,137, "Steve")
{
	std::cout << "+ShrubberyCreationForm+" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation",145,137, target)
{
	std::cout << "+ShrubberyCreationForm+" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "-ShrubberyCreationForm-" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getReqGradeExe())
		throw AForm::GradeTooLowException(); //Bureaucrat grade too low exception?
	else if(!this->getSigned())
		throw AForm::FormNotSignedException();
	else
	{
		//call a function
		std::cout << "<target> has been pardoned by ShrubberyCreationForm." << std::endl;
	}
}
