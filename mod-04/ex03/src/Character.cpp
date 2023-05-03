/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:19:52 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 16:19:53 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"
#include <iostream>
Character::Character()
{
	int i = 0;
	while(i < 4)
	{
		_materias[i] = nullptr;
		i++;
	}
}

Character::Character(std::string name)
{
	int i = 0;
	while(i < 4)
	{
		_materias[i] = nullptr;
		i++;
	}
	_name = name;
	std::cout << name <<" Character class was constructed" << std::endl;
}



// Character::Character(const Character& other)
// {
// 	(void) other;
// 	// std::cout << "Character class copy constructor was called" << std::endl;

// 	// _name = other._name;
// 	// for (int i = 0; i < 4; i++) {
// 	// 	if (other._materias[i] != nullptr) {
// 	// 		_materias[i] = other._materias[i]->clone();
// 	// 	} else {
// 	// 		_materias[i] = nullptr;
// 	// 	}
// 	// }
// }

// Character& Character::operator=(const Character& other)
// {
// 	if (this != &other) {
	
// 		_name = other._name;

// 		std::cout << "Character class copy assignment operator was called" << std::endl;

// 		for (int i = 0; i < 4; i++) {
// 			if (other._materias[i] != nullptr) {
// 				_materias[i] = other._materias[i]->clone();
// 			} else {
// 				 _materias[i] = nullptr;
// 			}
// 		}
// 	}
// 	return *this;
// 	return *this;
// }

//CHECK into this maybe aye?
Character::Character(const Character& to_copy_from)
{

	int i = 0;
	while(i < 4)
	{
		_materias[i] = nullptr;
		i++;
	}
	*this = to_copy_from;
}

Character& Character::operator=(const Character& other) 
{
	if(this == &other)
		return(*this);
	_name = other._name;
	int i = 0;
	while(i < 4)
	{
		if(other._materias[i] != nullptr)
		{
			equip(other._materias[i]);
		}
		i++;
	}
	return(*this);
}

std::string const& Character::getName() const
{
	return(_name);
}

void Character::equip(AMateria* m)
{
	if(m == nullptr)
	{
		std::cout << "please pass something valid " <<  std::endl;
		return ;
	}
	int i = 0;
	while(i < 4)
	{
		if(_materias[i] == nullptr)
		{
			_materias[i] = m;
			std::cout << _name << " equiped " << m->getType() << std::endl;
			return ;
		}
		i++;
	}
	std::cout << _name << " no space in the inventory for " << m->getType() << std::endl;
}
void Character::unequip(int idx)
{
	if(idx > -1 && idx < 4 && _materias[idx] != nullptr)
	{
		std::cout << _name << " unequip " << _materias[idx]->getType() <<std::endl;
		_materias[idx] = nullptr;
	}

}
void Character::use(int idx, ICharacter& target)
{
	if(idx > -1 && idx < 4 && _materias[idx] != nullptr)
	{
		_materias[idx]->use(target);
	}
	else
		std::cout << _name << " uses nothing at " << target.getName() << std::endl;
}

Character::~Character()
{
	std::cout << _name << " Character class was Destroyed" << std::endl;
}