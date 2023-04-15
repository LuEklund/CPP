/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:27:38 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 12:27:39 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
class HumanA
{
private:
	std::string _name;
	Weapon&		_wep;
public:
	void	attack();
	HumanA(std::string name, Weapon& wep);
	~HumanA();
};




#endif
