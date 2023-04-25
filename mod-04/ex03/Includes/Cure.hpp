/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:05:14 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 11:05:16 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure();
	Cure(const Cure& to_copy_from);
	Cure& operator=(const Cure& other);
	AMateria* clone() const;
	void use(ICharacter& target);
	~Cure();
};



#endif