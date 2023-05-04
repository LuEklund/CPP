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
Character::Character() : trash(nullptr)
{
	int i = 0;
	while(i < 4)
	{
		_materias[i] = nullptr;
		i++;
	}
}

Character::Character(std::string name) : trash(nullptr)
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

//CHECK into this maybe aye?
Character::Character(const Character& to_copy_from) : trash(nullptr)
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
			equip(other._materias[i]->clone());
		}
		i++;
	}
	return(*this);
}

void Character::addToTrash(AMateria* m)
{
		std::cout << "EQ" <<  std::endl;
	if(trash == nullptr)
	{
		std::cout << "EQ1" <<  std::endl;

		trash = new Trash(m);
	}
	else
	{
		std::cout << "EQ2" <<  std::endl;
		Trash *tmp = trash;
		while(tmp->Next() != nullptr)
		{
			if(tmp->getAmateria() == m)
			{
				std::cout << "Allready exists" <<  std::endl;
				return ;
			}
			tmp = tmp->Next();
		}
		if(tmp->getAmateria() == m)
		{
			std::cout << "Allready exists" <<  std::endl;
			return ;
		}
		tmp->setNext(new Trash(m));
	}
		std::cout << "EQ3" <<  std::endl;

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
		addToTrash(_materias[idx]);
		std::cout << "BULLSHIT" <<  std::endl;
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
	if(trash != nullptr)
	{
		trash->freeTrash();
	}
}