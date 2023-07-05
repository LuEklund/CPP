/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:13:53 by leklund           #+#    #+#             */
/*   Updated: 2023/07/05 16:13:54 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_HPP
# define INTERN_HPP
# include "Bureaucrat.hpp"

class Intern
{
typedef AForm *(Intern::*FormCreator)(std::string);
private:
	FormCreator formCreators[3];
	AForm* createPresidentialPardonForm(std::string target);
	AForm* createRobotomyRequestForm(std::string target);
	AForm* createShrubberyCreationForm(std::string target);

public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& copy);
	~Intern();
	AForm* makeForm(std::string FormType, std::string target);

};




#endif


