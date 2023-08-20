/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:32:48 by leklund           #+#    #+#             */
/*   Updated: 2023/08/20 08:32:50 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <iostream>


template<typename T>
void swap(T &val1, T &val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

template<typename T>
T &min(T &val1, T &val2)
{
	return (val1 < val2 ? val1 : val2);
}

template<typename T>
T &max(T &val1, T &val2)
{
	return (val1 > val2 ? val1 : val2);
}

#endif
