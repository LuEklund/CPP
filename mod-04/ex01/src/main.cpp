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
	std::cout << "==================================================" << std::endl;
	Animal *array[10];
	int i = 0;
	while(i < 10)
	{
	std::cout << "---------=[new Animal]+---------" << std::endl;

		if(i < 5)
			array[i] = new Cat();
		else
			array[i] = new Dog();
		i++;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	i = 0;

	while(i < 10)
	{
		std::cout << "---------=[remove Animal]+---------" << std::endl;
		delete array[i];
		i++;
	}
	std::cout << "==================================================" << std::endl;

	return (0);
}