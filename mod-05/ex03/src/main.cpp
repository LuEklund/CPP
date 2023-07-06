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
#include "Intern.hpp"

int main()
{
	std::cout << "==================================================" << std::endl;
	{
		Intern someRandomIntern;
		Bureaucrat Steve("Steve",1);
		AForm* rrf;
		rrf = someRandomIntern.makeForm("Wrong request", "Bender");
		rrf = someRandomIntern.makeForm("presidental request", "Bender");
		Steve.signAForm(*rrf);
		Steve.executeForm(*rrf);
		delete rrf;
	}
	std::cout << "==================================================" << std::endl;
	return (0);
}
