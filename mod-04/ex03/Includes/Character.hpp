/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:19:56 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 16:20:00 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_materias[4];
public:
	Character();
	Character(std::string name);
	Character(const Character& to_copy_from);
	Character& operator=(const Character& other) ;
	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	~Character();
};




#endif