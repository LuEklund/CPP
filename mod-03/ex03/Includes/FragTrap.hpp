/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:13:13 by leklund           #+#    #+#             */
/*   Updated: 2023/04/21 08:13:15 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	
public:
	FragTrap(void);
	FragTrap(std::string name);
	void highFivesGuys(void);
	unsigned int getAttack() const { return _attack; }
	~FragTrap();
};


#endif
