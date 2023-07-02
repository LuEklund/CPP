/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 06:01:01 by leklund           #+#    #+#             */
/*   Updated: 2023/07/02 06:01:03 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bob"), _grade(150) 
{
	std::cout << "+Const1: name:BOB lvl:150" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) 
{
	std::cout << "+Const2: name:" << name << " lvl:150" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "+Const3: name:" << name << " lvl:" << grade << std::endl;
	Bureaucrat::ApplyGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name)
{
	std::cout << "+copyConst: name:" << copy._name << " lvl:" << copy._grade << std::endl;
	this->_grade = copy._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::cout << "+copyAsign: Bureaucrat [" << this->_name << "] got lvl:" << copy._grade << " from [" << copy._name << "]" << std::endl;
	if(this == &copy)
		return(*this);
	this->_grade = copy._grade;
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "-deConst: name:" << this->_name << " lvl:" << this->_grade << std::endl;
}

const std::string Bureaucrat::getName()
{
	return (_name);
}

int Bureaucrat::getGrade()
{
	return (_grade);
}

void Bureaucrat::IncrementGrade()
{
	std::cout << "[IncrementGrade]: name:" << this->_name << " (" << this->_grade << "->" << (this->_grade - 1) << ")" << std::endl;
	ApplyGrade(this->_grade - 1);
}

void Bureaucrat::DecrementGrade()
{
	std::cout << "[DecrementGrade]: name:" << this->_name << " (" << this->_grade << "->" << (this->_grade + 1) << ")" << std::endl;
	ApplyGrade(this->_grade + 1);
}

void Bureaucrat::ApplyGrade(int grade)
{
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

std::ostream& operator<<(std::ostream& outPut, Bureaucrat& b)
{
	outPut << "[!]" << b.getName() << ", bureaucrat grade:" << b.getGrade();
	return (outPut);
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade Too High Exception";	
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade Too Low Exception";	
}


