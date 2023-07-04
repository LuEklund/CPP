/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:31:56 by leklund           #+#    #+#             */
/*   Updated: 2023/07/04 07:31:57 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	
public:
	PresidentialPardonForm();
	virtual ~PresidentialPardonForm();
};

// std::ostream& operator<<(std::ostream& outPut, PresidentialPardonForm& form);

#endif
