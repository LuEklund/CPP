/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:31 by leklund           #+#    #+#             */
/*   Updated: 2023/07/03 13:43:32 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _reqGradeSign(1), _reqGradeExe(1)
{
	std::cout << "+ConstAForm: name:default reqGradeSign:1 reqGradeExe:1" << std::endl;
}

AForm::AForm(std::string name, int reqSign, int reqExe) : _name(name), _signed(false), _reqGradeSign(reqSign), _reqGradeExe(reqExe)
{
	std::cout << "+ConstAForm1: name:" << name << " reqGradeSign:" << reqSign << " reqGradeExe:" << reqExe << std::endl;
	if(_reqGradeExe < 1 || _reqGradeSign < 1)
		throw AForm::GradeTooHighException();
	else if (_reqGradeExe > 150 || _reqGradeSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _reqGradeSign(copy._reqGradeSign), _reqGradeExe(copy._reqGradeExe)
{
	std::cout << "+copyConstAForm: name:" << copy._name << " signed:" << copy._signed << \
	" reqSign:" << copy._reqGradeSign << " reqExe:" << copy._reqGradeExe << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
	std::cout << "+copyAsign: AForm [" << this->_name << "] got signed:" << copy._signed << " from [" << copy._name << "]" << std::endl;
	if(this == &copy)
		return(*this);
	this->_signed = copy._signed;
	return(*this);
}

AForm::~AForm()
{
	std::cout << "-deConstAForm: name:" << this->_name << " sgined:" << this->_signed << std::endl;
}

void AForm::beSigned(Bureaucrat& bur)
{
	if(bur.getGrade() > this->_reqGradeSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

const std::string AForm::getName()
{
	return(_name);
}
bool AForm::getSigned()
{
	return(_signed);
}
int AForm::getReqGradeSign()
{
	return(_reqGradeSign);
}
int AForm::getReqGradeExe()
{
	return(_reqGradeExe);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("AForm: Grade Too High Exception");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return("AForm: Grade Too Low Exception");
}

std::ostream& operator<<(std::ostream& outPut, AForm& f)
{
	outPut << "[!]AForm:" << f.getName() << " isSigned[" << f.getSigned() << "] reqSign[" \
	<< f.getReqGradeSign() << "] reqExe[" << f.getReqGradeExe() <<"]";
	return(outPut);
}

