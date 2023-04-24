/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:24:56 by leklund           #+#    #+#             */
/*   Updated: 2023/04/23 07:24:57 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal class was constructed" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "this is Animal sound" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal class was destroyed" << std::endl;

}