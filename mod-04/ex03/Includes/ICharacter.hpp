/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:10:27 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 16:10:28 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <string>

class AMateria;

class ICharacter
{
	public:
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
	virtual ~ICharacter() {}
};

#endif
