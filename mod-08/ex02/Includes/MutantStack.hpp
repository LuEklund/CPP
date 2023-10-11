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
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &copy);
public:
	typedef typename std::deque<T>::iterator iterator;
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
};

#endif
