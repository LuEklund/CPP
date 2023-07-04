/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:27:05 by leklund           #+#    #+#             */
/*   Updated: 2023/07/04 07:27:06 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest",72,45,"Steve")
{
	std::cout << "+RobotomyRequestForm+" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest",72,45,target)
{
	std::cout << "+RobotomyRequestForm+" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "-RobotomyRequestForm-" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getReqGradeExe())
		throw AForm::GradeTooLowException();
	else if(!this->getSigned())
		throw AForm::FormNotSignedException();
	else
	{
		//call a function
		std::cout << "<target> has been pardoned by RobotomyRequestForm." << std::endl;
	}
}
