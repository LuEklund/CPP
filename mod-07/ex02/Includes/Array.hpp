/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:32:48 by leklund           #+#    #+#             */
/*   Updated: 2023/08/20 08:32:50 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>






template<typename T>
class Array
{
private:
	unsigned int	_size;
	T				*_array;
public:
	Array();
	Array(unsigned int n);
	Array(Array<T> const &copy);
	Array<T> &operator=(Array<T> const &copy);
	T &operator[](const unsigned int index) const;
	unsigned int size() const;
	~Array();
};

#include "../src/Array.tpp"

#endif
