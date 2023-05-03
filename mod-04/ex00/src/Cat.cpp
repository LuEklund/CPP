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
}

Cat::Cat(const Cat& to_copy_from)
{
	*this = to_copy_from;
}

Cat& Cat::operator=(const Cat& other)
{
	if(this == &other)
		return(*this);
	type = other.type;
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "this is Cat sound" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat class was destroyed" << std::endl;

}
