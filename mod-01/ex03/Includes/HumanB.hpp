/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:27:32 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 12:27:34 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon*		_wep;
public:
	void	attack();
	void	setWeapon(Weapon& wep);
	HumanB(std::string name);
	~HumanB();
};



#endif

