/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:16:59 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 10:17:00 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include <iostream>
# include "ICharacter.hpp"

// class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& to_copy_from);
	AMateria& operator=(const AMateria& other);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	virtual ~AMateria();
};

#endif