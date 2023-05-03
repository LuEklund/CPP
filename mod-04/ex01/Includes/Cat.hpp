/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:40:45 by leklund           #+#    #+#             */
/*   Updated: 2023/04/23 07:40:46 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"


class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat &);
	Brain& getBrain();
	virtual void makeSound() const;
	virtual ~Cat();
};



#endif
