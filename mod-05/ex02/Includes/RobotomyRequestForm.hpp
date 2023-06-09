/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:31:40 by leklund           #+#    #+#             */
/*   Updated: 2023/07/04 07:31:41 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	void RobotomyRequest(const std::string target) const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &);
	~RobotomyRequestForm();
	void execute(Bureaucrat const & executor) const;


};

#endif



