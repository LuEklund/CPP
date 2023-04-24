/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:20:21 by leklund           #+#    #+#             */
/*   Updated: 2023/04/23 08:20:22 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRONG_ANIMAL_CPP
# define WRONG_ANIMAL_CPP
# include <string>
# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
	
public:
	WrongAnimal();
	std::string getType() const;
	void makeSound() const;
	~WrongAnimal();
};

#endif


