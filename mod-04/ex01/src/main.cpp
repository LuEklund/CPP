/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:09:05 by leklund           #+#    #+#             */
/*   Updated: 2023/04/22 11:09:07 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
	
	int array_size = 4;
	std::cout << "==================================================" << std::endl;
	Animal *array[array_size];
	int i = 0;
	while(i < array_size)
	{
	std::cout << "[" << i+1 << "]" << "---------=[new Animal]=---------" << std::endl;

		if(i < array_size/2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
		i++;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	i = 0;

	while(i < array_size)
	{
		std::cout << "[" << i+1 << "]" << "---------=[remove Animal]=---------" << std::endl;
		delete array[i];
		i++;
	}
	std::cout << "==================================================" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "====================[new]=========================" << std::endl;
	Dog *basic = new Dog();
	basic->getBrain().setIdea(0, "cool brain");
	basic->getBrain().setIdea(101, "cool brain");
	Dog tmp = *basic;
	delete basic;
	std::cout << "--------------------------------------------------" << std::endl;	
	std::cout << "brain Idea: " << tmp.getBrain().getIdea(0) << std::endl;
	std::cout << "brain Idea: " << tmp.getBrain().getIdea(-1) << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;


	std::cout << "==================================================" << std::endl;


	return (0);
}