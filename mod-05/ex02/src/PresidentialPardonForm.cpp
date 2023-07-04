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

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon",25,5,"Steve")
{
	std::cout << "+PresidentialPardonForm+" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon",25,5,target)
{
	std::cout << "+PresidentialPardonForm1+" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "-PresidentialPardonForm-" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getReqGradeExe())
		throw AForm::GradeTooLowException();
	else if(!this->getSigned())
		throw AForm::FormNotSignedException();
	else
	{
		//call function
		std::cout << "<target> has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}
// std::ostream& operator<<(std::ostream& outPut, PresidentialPardonForm& form)
// {
// 	(void) form;
// 	outPut << "sus" << std::endl;
// 	return(outPut);
// }
