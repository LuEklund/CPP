/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:43:08 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 08:43:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombies = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        zombies[i].setName(name);
    }

    return zombies;
}
