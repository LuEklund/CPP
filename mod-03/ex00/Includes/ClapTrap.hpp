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

class ClapTrap
{
private:
	std::string	_name;
	int			_health;
	int			_energy;
	int			_attack;
public:
	ClapTrap(std::string name);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};



#endif