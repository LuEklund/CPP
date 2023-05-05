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
	for(int i = 0; i < 4; i++)
	{
		_materias[i] = to_copy_from._materias[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) 
{
	if(this == &other)
		return(*this);
	for(int i = 0; i < 4; i++)
	{
		delete _materias[i];
		_materias[i] = other._materias[i];
	}
	return(*this);
}

void MateriaSource::learnMateria(AMateria* toSave)
{
	int i = 0;
	while(i < 4)
	{
		if(_materias[i] == nullptr)
		{
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
	while(i < 4)
	{
		if(_materias[i] != nullptr && _materias[i]->getType() == type)
			return(_materias[i]->clone());
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
			delete _materias[i];
		}
		i++;
	}
	std::cout << "MateriaSource class was Destroyed" << std::endl;

}