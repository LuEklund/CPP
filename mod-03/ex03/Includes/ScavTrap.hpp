/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:23:53 by leklund           #+#    #+#             */
/*   Updated: 2023/04/20 15:23:54 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	void attack(const std::string& target);
	void guardGate();
	~ScavTrap();
};


#endif
