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

Dog::Dog()
{
	type = "Dog";
	std::cout << type << " class was constructed" << std::endl;
	brain = new Brain;

}

Dog::Dog(const Dog& to_copy_from)
{
	*this = to_copy_from;
}

Dog& Dog::operator=(const Dog& other) 
{
	if(this == &other)
		return(*this);
	delete this->brain;
	this->brain = new Brain(*other.brain);
	type = other.type;
	return(*this);
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
