/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:11:08 by leklund           #+#    #+#             */
/*   Updated: 2023/04/13 20:11:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"


int main ()
{
	randomChump("zombie1");
	Zombie* zombiePtr = newZombie("Peter");
	delete (zombiePtr);
	return(0);
}