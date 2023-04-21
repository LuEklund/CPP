/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:39 by leklund           #+#    #+#             */
/*   Updated: 2023/04/20 14:40:41 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_health;
	unsigned int	_energy;
	unsigned int	_attack;
	bool			isWorking();
public:
	ClapTrap(std::string name, unsigned int health, unsigned int energy, unsigned int attack);
	ClapTrap(std::string name);
	ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string		getName(void);
	unsigned int	getHealth(void);
	unsigned int	getEnergy(void);
	unsigned int	getAttack(void);
	bool			setEnergy(int amount);

	~ClapTrap();
};



#endif