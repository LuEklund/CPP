/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:32:48 by leklund           #+#    #+#             */
/*   Updated: 2023/08/20 08:32:50 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <vector>


class Span
{
private:
	std::vector<int>	_vec;
	unsigned int 		_size;
public:
	Span(unsigned int n);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span();
	void			addNumber(int number);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	void			addNumbers(const unsigned int amount);
	

};

#endif
