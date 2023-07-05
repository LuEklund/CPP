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
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145,137, "Steve")
{
	std::cout << "+ShrubberyCreationForm+" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation",145,137, target)
{
	std::cout << "+ShrubberyCreationForm+" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy.getName(), copy.getReqGradeSign(), copy.getReqGradeExe(), copy.getTarget())
{
	if(copy.getSigned())
		this->Sign();
	std::cout << "+copyConstShrubberyCreationForm: name:" << copy.getName() << " signed:" << copy.getSigned() << \
	" reqSign:" << copy.getReqGradeSign() << " reqExe:" << copy.getReqGradeExe() << "Target: " << copy.getTarget() << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	std::cout << "+copyAsign: ShrubberyCreationForm [" << this->getName() << "] got signed:" << copy.getSigned() << " from [" << copy.getName() << "]" << std::endl;
	if(this == &copy)
		return(*this);
	if(copy.getSigned())
		this->Sign();
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "-ShrubberyCreationForm-" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getReqGradeExe())
		throw Bureaucrat::GradeTooLowException(); //Bureaucrat grade too low exception?
	else if(!this->getSigned())
		throw AForm::FormNotSignedException();
	else
		ShrubberyCreation(this->getTarget());
}

void ShrubberyCreationForm::ShrubberyCreation(const std::string target) const
{
	std::ofstream outputFile(target + "_shrubbery");
	if (!outputFile.is_open()) {
		std::cerr << "Error opening output file: " << target + "_shrubbery" << std::endl;
		return;
	}
	std::string line = 
	"     ^\n"
    "    ^^^\n"
    "   ^^^^^\n"
    "  ^^^^^^^\n"
    " ^^^^^^^^^\n"
    "^^^^^^^^^^^\n"
    "     I\n";
	for(int i = 3; i > 0; i--)
	{
		outputFile << line << std::endl;
	}
	outputFile.close();
}