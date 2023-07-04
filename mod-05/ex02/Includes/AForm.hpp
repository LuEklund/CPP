/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:18 by leklund           #+#    #+#             */
/*   Updated: 2023/07/03 13:43:20 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string 	_name;
	bool				_signed;
	const int			_reqGradeSign;
	const int			_reqGradeExe;
public:
	AForm();
	AForm(std::string name, int reqSign, int reqExe);
	AForm(const AForm& other);
	AForm& operator=(const AForm &);
	virtual ~AForm();
	void beSigned(Bureaucrat& bur);
	const std::string getName();
	bool getSigned();
	int getReqGradeSign();
	int getReqGradeExe();
class GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw();
};
class GradeTooLowException : public std::exception
{
	public:
		const char * what() const throw();
};
};

std::ostream& operator<<(std::ostream& outPut, AForm& b);

#endif
