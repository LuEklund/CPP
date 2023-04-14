/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:11:33 by leklund           #+#    #+#             */
/*   Updated: 2023/04/13 20:11:35 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream> 
# include <string>

class Zombie
{
private:
	std::string	name;
public:
	void announce( void );
	Zombie(std::string name);
	~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );



#endif
