/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 07:14:35 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 07:14:37 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain was constructed" << std::endl;
}

Brain::Brain(const Brain& to_copy_from)
{
	*this = to_copy_from;
}

Brain& Brain::operator=(const Brain& other) 
{
	std::cout << "CPYYYYYYY" << std::endl;
	if(this == &other)
		return(*this);
	std::cout << "CPYYYYYYY" << std::endl;
	int i = 0;
	while(other.ideas[i].size() && i < 100)
	{
		std::cout << "copy: "<< i << ", word is: " << other.ideas[i] << std::endl;
		ideas[i] = other.ideas[i];
		i++;
	}
	
	return(*this);
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed" << std::endl;
}