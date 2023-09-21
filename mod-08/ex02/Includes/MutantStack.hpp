/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:32:48 by leklund           #+#    #+#             */
/*   Updated: 2023/08/20 08:32:50 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <vector>
# include <stack>
# include <iostream>



template<typename T>
class MutantStack : public std::stack<T>
{
private:
	
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	MutantStack(){}
	~MutantStack(){}

	iterator begin()
	{
    	return (this->c.begin());
	}

	iterator end()
	{
    	return (this->c.end());
	}

	const_iterator begin() const
	{
    	return (this->c.begin());
	}

	const_iterator end() const
	{
		return (this->c.end());
	}
};

//#include "../src/MutantStack.tpp"

#endif
