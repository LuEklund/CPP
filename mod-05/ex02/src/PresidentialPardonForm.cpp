/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:27:45 by leklund           #+#    #+#             */
/*   Updated: 2023/07/04 07:27:46 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25,5,"Steve")
{
	std::cout << "+PresidentialPardonForm+" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon",25,5,target)
{
	std::cout << "+PresidentialPardonForm1+" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy.getName(), copy.getReqGradeSign(), copy.getReqGradeExe(), copy.getTarget())
{
	if(copy.getSigned())
		this->Sign();
	std::cout << "+copyConstPresidentialPardonForm: name:" << copy.getName() << " signed:" << copy.getSigned() << \
	" reqSign:" << copy.getReqGradeSign() << " reqExe:" << copy.getReqGradeExe() << "Target: " << copy.getTarget() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	std::cout << "+copyAsign: PresidentialPardonForm [" << this->getName() << "] got signed:" << copy.getSigned() << " from [" << copy.getName() << "]" << std::endl;
	if(this == &copy)
		return(*this);
	if(copy.getSigned())
		this->Sign();
	return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "-PresidentialPardonForm-" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getReqGradeExe())
		throw Bureaucrat::GradeTooLowException();
	else if(!this->getSigned())
		throw AForm::FormNotSignedException();
	else
	{
		PresidentialPardon(this->getTarget());
	}
}

void PresidentialPardonForm::PresidentialPardon(const std::string target) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
