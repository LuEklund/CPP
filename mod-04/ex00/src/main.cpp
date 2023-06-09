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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "--------------------------------------------------" << std::endl;

	delete meta;
	delete j;
	delete i;
	std::cout << "==================================================" << std::endl;
	std::cout << "==================================================" << std::endl;
	const WrongAnimal* nCat = new WrongCat();
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << nCat->getType() << " " << std::endl;
	nCat->makeSound(); //will output the cat sound!

	std::cout << "--------------------------------------------------" << std::endl;

	delete nCat;
	std::cout << "==================================================" << std::endl;
	return (0);
}