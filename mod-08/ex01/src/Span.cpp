/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:09:09 by leklund           #+#    #+#             */
/*   Updated: 2023/08/18 10:09:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"



Span::Span(unsigned int n) : _size(n)
{
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if(_vec.size() >= _size)
        throw std::exception();
    _vec.push_back(number);
}

unsigned int	Span::shortestSpan()
{
    if(_vec.size() < 2)
        throw std::exception();
    unsigned int smallest = std::numeric_limits<unsigned int>::max();
    unsigned int span = 0;
    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    for(unsigned int i = 0; i < _vec.size() - 1; i++)
    {
        span = std::abs(sorted[i] - sorted[i + 1]);
        if (span < smallest)
            smallest = span;
    }
    return(smallest);
}


unsigned int	Span::longestSpan()
{
    if(_vec.size() < 2)
        throw std::exception();
    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    return (_vec.back() - _vec.front());
}
