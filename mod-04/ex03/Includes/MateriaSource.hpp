/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:01:03 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 18:01:04 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materias[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& to_copy_from);
	MateriaSource& operator=(const MateriaSource& other) ;
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	~MateriaSource();
};




#endif
