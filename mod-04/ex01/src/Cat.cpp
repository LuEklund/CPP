/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:40:39 by leklund           #+#    #+#             */
/*   Updated: 2023/04/23 07:40:41 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << type << " class was constructed" << std::endl;
	brain = new Brain;
}

Cat::Cat(const Cat& to_copy_from)
{
	brain = new Brain(*to_copy_from.brain);
	type = to_copy_from.type;
}

Cat& Cat::operator=(const Cat& other) 
{
	if(this == &other)
		return(*this);
	Brain * new_brain = new Brain(*other.brain);
	delete brain;
	brain = new_brain;
	type = other.type;
	return(*this);
}

Brain& Cat::getBrain()
{
	return(*brain);
}


void Cat::makeSound() const
{
	std::cout << "this is Cat sound" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat class was destroyed" << std::endl;
}
