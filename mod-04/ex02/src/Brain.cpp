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
	std::cout << "COPY brain called" << std::endl;
	if(this == &other)
		return(*this);
	int i = 0;
	while(other.ideas[i].size() && i < 100)
	{
		std::cout << "copy: "<< i << ", word is: " << other.ideas[i] << std::endl;
		ideas[i] = other.ideas[i];
		i++;
	}
	
	return(*this);
}

void Brain::setIdea(size_t index, std::string idea)
{
	if(index < 100 && index >= 0)
	{
		ideas[index] = idea;
	}
	else
		std::cout << "Dont have the Brain capacitty for this" << std::endl;
}

std::string Brain::getIdea(size_t index)
{
	if(index < 100 && index >= 0)
	{
		if(ideas[index].length())
			return(ideas[index]);
	}
	return("No Idea");
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed" << std::endl;
}