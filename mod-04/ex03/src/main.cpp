/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:23:10 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 10:23:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);

	// // me->equip(tmp);
	// // me->equip(tmp);
	// me->unequip(0);
	// me->unequip(1);
	// // me->unequip(2);
	// // me->unequip(3);
	delete tmp;
	delete me;
	delete src;

	// {
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// me->unequip(0);
	// me->use(0, *bob);
	// me->unequip(0);
	// std::cout << "------------------------------------------------" << std::endl;
	// delete me;
	// std::cout << "------------------------------------------------" << std::endl;
	// std::cout << "=================================================" << std::endl;
	// Character *me2 = new Character("me");
	// me2->equip(tmp);
	// me2->use(0, *bob);
	// me2->unequip(0);
	// Character *bob2 = new Character(*me2);
	// delete me2;
	// bob2->use(0, *bob);
	// std::cout << "=================================================" << std::endl;
	// std::cout << "------------------------------------------------" << std::endl;
	// delete bob2;
	// delete bob;
	// delete src;
	// delete tmp;
	// std::cout << "------------------------------------------------" << std::endl;
	// }

	return(0);
}
