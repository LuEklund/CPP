/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 06:01:23 by leklund           #+#    #+#             */
/*   Updated: 2023/07/02 06:01:24 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"



class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		void ApplyGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat &);
		~Bureaucrat();
		void signAForm(AForm& Aform);
		const std::string getName();
		int getGrade() const;
		void IncrementGrade();
		void DecrementGrade();
		void executeForm(AForm const & form);
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};
		std::ostream& operator<<(std::ostream& outPut, Bureaucrat& b);

#endif



