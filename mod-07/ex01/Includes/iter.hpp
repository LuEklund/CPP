/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:32:48 by leklund           #+#    #+#             */
/*   Updated: 2023/08/20 08:32:50 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>


template<typename T>
void iter(T *array,	size_t len, void (*function)(T const &))
{
	for(size_t i = 0; i < len; i++)
	{
		function(array[i]);
	}
	return ;
}

template<typename T>
void	multiplier(T value)
{
	std::cout << "Value " << value << " * 2 = " << value*2 << std::endl;
	return;
}

#endif
