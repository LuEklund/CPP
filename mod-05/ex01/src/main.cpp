/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:09:05 by leklund           #+#    #+#             */
/*   Updated: 2023/04/22 11:09:07 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "==================================================" << std::endl;
		try
		{
			Form Form1("Form1",1211,12);
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cout << "Grade too LOW" << std::endl;
		}
	}
	{
		std::cout << "==================================================" << std::endl;
		try
		{
			Form Form2("Form2",12,300);
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cout << "Grade too LOW" << std::endl;
		}
	}
	{
		std::cout << "==================================================" << std::endl;
		try
		{
			Form Form3("Form3",0,3);
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cout << "Grade too HIGH" << std::endl;
		}
	}
	{
		std::cout << "==================================================" << std::endl;
		try
		{
			Form Form4("Form4",67,-3);
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cout << "Grade too HIGH" << std::endl;
		}
	}
	{
		std::cout << "==================================================" << std::endl;
		Bureaucrat Assitant("Assitant", 120);	
		Bureaucrat CEO("CEO", 1);	
		Form Form5("Form5",42,43);
		std::cout << Form5 << std::endl;
		Assitant.signForm(Form5);
		std::cout << Form5 << std::endl;
		CEO.signForm(Form5);
		std::cout << Form5 << std::endl;
	}
	{
		std::cout << "==================================================" << std::endl;
		Bureaucrat Peter("Peter", 3);	
		Form Form6("Form6",42,43);
		Form Form7(Form6);
		Peter.signForm(Form7);
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << Form6 << std::endl;
		std::cout << Form7 << std::endl;
		Form Form8 = Form7;
		std::cout << Form8 << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
	}
	std::cout << "==================================================" << std::endl;
	return (0);
}		

// Peter.signForm(Form1);
		// Peter.signForm(Form1);
		// try
		// {
		// 	low.DecrementGrade();
		// 	low.DecrementGrade();
		// }
		// catch(Bureaucrat::GradeTooLowException& e)
		// {
		// 	std::cout << "cannot Decrement grade" << std::endl;
		// }