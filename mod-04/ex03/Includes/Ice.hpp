/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:05:02 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 11:05:04 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	Ice(const Ice& to_copy_from);
	Ice& operator=(const Ice& other);
	AMateria* clone() const;
	void use(ICharacter& target);
	~Ice();
};



#endif
