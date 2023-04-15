/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:28:04 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 12:28:05 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
class Weapon
{
private:
	std::string _type;
public:
	const	std::string getType(void);
	void	setType(std::string type);
	Weapon(std::string type);
	~Weapon();
};




#endif

