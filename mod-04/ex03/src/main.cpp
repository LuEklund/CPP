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
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	// me->unequip(0);
	// me->use(0, *bob);
	// me->unequip(0);
	// std::cout << "=================================================" << std::endl;
	// ICharacter* dod = new Character("dod");
	// dod = me;
	// std::cout << "------------------------------------------------" << std::endl;

	// dod = me;
	delete bob;
	delete me;
	delete src;



	// delete dod;

	return(0);
}
