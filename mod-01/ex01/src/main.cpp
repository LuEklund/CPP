/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:42:51 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 08:42:53 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/Zombie.hpp"

int main()
{
	Zombie* zom = zombieHorde(4, "Steves");
	delete[] zom;
	return (0);
}
