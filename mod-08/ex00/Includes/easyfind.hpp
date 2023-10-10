/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:32:48 by leklund           #+#    #+#             */
/*   Updated: 2023/08/20 08:32:50 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>


template<typename T>
typename T::iterator easyfind(T &conatiner, int value)
{
	typename T::iterator it = std::find(conatiner.begin(), conatiner.end(), value);
	if(it == conatiner.end())
		throw std::exception();
	else
		return it;
}

#endif
