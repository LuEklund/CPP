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
}

void Dog::makeSound() const
{
	std::cout << "this is Dog sound" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog class was destroyed" << std::endl;

}
