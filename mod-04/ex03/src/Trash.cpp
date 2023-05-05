/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trash.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:35:59 by leklund           #+#    #+#             */
/*   Updated: 2023/05/04 12:36:01 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Trash.hpp"

Trash::Trash() : materia(nullptr), next(nullptr)
{

}

Trash::Trash(AMateria *m) : materia(m), next(nullptr)
{
	
}

Trash::Trash(const Trash& to_copy_from)
{
	materia = to_copy_from.materia;
	next = to_copy_from.next;
}

Trash& Trash::operator=(const Trash& other) 
{
	if(this == &other)
		return(*this);
	materia = other.materia;
	next = other.next;
	return(*this);
}

Trash *Trash::Next()
{
	return (next);
}

void Trash::setNext(Trash* to_set)
{
	next = to_set;
}

AMateria *Trash::getAmateria()
{
	return(materia);
}


// void Trash::freeTrash()
// {
// 	std::cout << "Start freeing " <<  std::endl;
// 	if(materia != nullptr)
// 	{
// 	std::cout << "A" <<  std::endl;
// 		delete materia;
// 	std::cout << "B" <<  std::endl;

// 		Trash *tmp = this;
// 	std::cout << "C" <<  std::endl;
// 		while(tmp->next != nullptr)
// 		{
// 			std::cout << "CWHAT" <<  std::endl;
// 			tmp = tmp->next;
// 			std::cout << "CWHAT1" <<  std::endl;
// 			delete tmp->materia;
// 			std::cout << "CWHAT2" <<  std::endl;
// 		}

// 	std::cout << "D" <<  std::endl;
// 	}
// }

Trash::~Trash()
{
	delete materia;
	materia = nullptr;
	delete next;
	next = nullptr;

}