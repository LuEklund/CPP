/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:00:57 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 18:00:59 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int i = 0;
	while(i < 4)
	{
		_materias[i] = nullptr;
		i++;
	}
	std::cout << "MateriaSource class was constructed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& to_copy_from)
{
	*this = to_copy_from;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) 
{
	if(this == &other)
		return(*this);
		//deep copy materias
	return(*this);
}

void MateriaSource::learnMateria(AMateria* toSave)
{
	int i = 0;
	while(i < 4)
	{
		std::cout << "_materias[" << i << "] = " << std::endl;
		// std::cout << "_materias[" << i << "] = " << _materias[i]->getType() << std::endl;
		if(_materias[i] == nullptr)
		{
			// AMateria *tmp = toSave->clone();
			// _materias[i] = tmp;
			_materias[i] = toSave;
			return;
		}
		i++;
	}
		std::cout << " cannot learn is full " << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	// std::cout << " createMateria = " << type << std::endl;
	while(i < 4)
	{
		// std::cout << "_materias[" << i << "] = ";
		// if(_materias[i] != nullptr)
		// 	std::cout << _materias[i]->getType() << " ?= " << type;
		// std::cout << std::endl;
		if(_materias[i] != nullptr && _materias[i]->getType() == type)
			return(_materias[i]);
		i++;
	}
	std::cout << " createMateria failed :(" << std::endl;
	return(0);
}

MateriaSource::~MateriaSource()
{
	int i = 0;
	while(i < 4)
	{
		if(_materias[i] != nullptr)
		{
			// std::cout << "to delete _materias[" << i << "] = " << _materias[i]->getType() << std::endl;

			delete _materias[i];
		}
		i++;
	}
	std::cout << "MateriaSource class was Destroyed" << std::endl;

}