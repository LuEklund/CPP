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

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",72,45,"Steve")
{
	std::cout << "+RobotomyRequestForm+" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest",72,45,target)
{
	std::cout << "+RobotomyRequestForm+" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy.getName(), copy.getReqGradeSign(), copy.getReqGradeExe(), copy.getTarget())
{
	if(copy.getSigned())
		this->Sign();
	std::cout << "+copyConstRobotomyRequestForm: name:" << copy.getName() << " signed:" << copy.getSigned() << \
	" reqSign:" << copy.getReqGradeSign() << " reqExe:" << copy.getReqGradeExe() << "Target: " << copy.getTarget() << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	std::cout << "+copyAsign: RobotomyRequestForm [" << this->getName() << "] got signed:" << copy.getSigned() << " from [" << copy.getName() << "]" << std::endl;
	if(this == &copy)
		return(*this);
	if(copy.getSigned())
		this->Sign();
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "-RobotomyRequestForm-" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getReqGradeExe())
		throw Bureaucrat::GradeTooLowException();
	else if(!this->getSigned())
		throw AForm::FormNotSignedException();
	else
		RobotomyRequest(this->getTarget());
}

void RobotomyRequestForm::RobotomyRequest(const std::string target) const
{
	std::srand(std::time(0));
	if((rand() % 2))
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "the robotomy failed." << std::endl;

}
