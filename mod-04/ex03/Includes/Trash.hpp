/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trash.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:36:05 by leklund           #+#    #+#             */
/*   Updated: 2023/05/04 12:36:07 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TRASH_HPP
# define TRASH_HPP
# include "AMateria.hpp"


class Trash
{
private:
	AMateria *materia;
	Trash *next;
public:
	Trash();
	Trash(AMateria *m);
	Trash(const Trash& to_copy_from);
	Trash& operator=(const Trash& other) ;
	Trash* Next();
	void setNext(Trash* to_add);
	AMateria *getAmateria();
	// void freeTrash();
	~Trash();
};



#endif
