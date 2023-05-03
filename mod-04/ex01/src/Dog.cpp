/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:40:53 by leklund           #+#    #+#             */
/*   Updated: 2023/04/23 07:40:54 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"

Dog::Dog() : brain(nullptr)
{
	type = "Dog";
	std::cout << type << " class was constructed" << std::endl;
	brain = new Brain;

}

Dog::Dog(const Dog& to_copy_from)
{
	std::cout << "CPY constructor" << std::endl;
	brain = new Brain(*to_copy_from.brain);
	type = to_copy_from.type;
}

Dog& Dog::operator=(const Dog& other) 
{
	std::cout << "CPY assingment" << std::endl;
	if(this == &other)
		return(*this);
	Brain * new_brain = new Brain(*other.brain);
	delete brain;
	brain = new_brain;
	type = other.type;
	return(*this);

}


Brain& Dog::getBrain()
{
	return(*brain);
}

void Dog::makeSound() const
{
	std::cout << "this is Dog sound" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog class was destroyed" << std::endl;
}
