/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:31 by leklund           #+#    #+#             */
/*   Updated: 2023/07/03 13:43:32 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _reqGradeSign(1), _reqGradeExe(1)
{
	std::cout << "+ConstForm: name:default reqGradeSign:1 reqGradeExe:1" << std::endl;
}

Form::Form(std::string name, int reqSign, int reqExe) : _name(name), _signed(false), _reqGradeSign(reqSign), _reqGradeExe(reqExe)
{
	std::cout << "+ConstForm1: name:" << name << " reqGradeSign:" << reqSign << " reqGradeExe:" << reqExe << std::endl;
	if(_reqGradeExe < 1 || _reqGradeSign < 1)
		throw Form::GradeTooHighException();
	else if (_reqGradeExe > 150 || _reqGradeSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _reqGradeSign(copy._reqGradeSign), _reqGradeExe(copy._reqGradeExe)
{
	std::cout << "+copyConstForm: name:" << copy._name << " signed:" << copy._signed << \
	" reqSign:" << copy._reqGradeSign << " reqExe:" << copy._reqGradeExe << std::endl;
}

Form& Form::operator=(const Form& copy)
{
	std::cout << "+copyAsign: Form [" << this->_name << "] got signed:" << copy._signed << " from [" << copy._name << "]" << std::endl;
	if(this == &copy)
		return(*this);
	this->_signed = copy._signed;
	return(*this);
}

Form::~Form()
{
	std::cout << "-deConstForm: name:" << this->_name << " sgined:" << this->_signed << std::endl;
}

void Form::beSigned(Bureaucrat& bur)
{
	if(bur.getGrade() > this->_reqGradeSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const std::string Form::getName()
{
	return(_name);
}
bool Form::getSigned()
{
	return(_signed);
}
int Form::getReqGradeSign()
{
	return(_reqGradeSign);
}
int Form::getReqGradeExe()
{
	return(_reqGradeExe);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Form: Grade Too High Exception");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return("Form: Grade Too Low Exception");
}

std::ostream& operator<<(std::ostream& outPut, Form& f)
{
	outPut << "[!]Form:" << f.getName() << " isSigned[" << f.getSigned() << "] reqSign[" \
	<< f.getReqGradeSign() << "] reqExe[" << f.getReqGradeExe() <<"]";
	return(outPut);
}

