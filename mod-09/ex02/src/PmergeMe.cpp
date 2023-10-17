/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:09:18 by leklund           #+#    #+#             */
/*   Updated: 2023/10/12 22:09:20 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

};

PmergeMe::~PmergeMe()
{

};
int	PmergeMe::ft_stoi(std::string value)
{
	std::stringstream	ss;
	unsigned int		res;
	unsigned int		len = value.length();

	if (len > 10)
		return (-1);
	for(size_t i = 0; i < len; i++)
	{
		if(!isdigit(value[i]))
			return(-1);
	}
	ss.str(value);
	ss >> res;
	if (ss.fail() == true || res > INT_MAX)
		return (-1);
	return(res);
}

int	PmergeMe::saveValidInput(int argc, char **argv)
{
	int	value;
	for(int i = 1; i < argc; i++)
	{
		if((value = ft_stoi(argv[i])) != -1)
		{
			vec.push_back(value);
			deq.push_back(value);
		}
		else
			return (INAVLID_VALUE);
		size = i - 1;
	}
	return (OK);
}

//2147483647, -2147483648
int	PmergeMe::action()
{
	std::cout << "Vector" << std::endl;
	for(vector::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
		std::cout << ", " << *it;
	}

	std::cout << std::endl << "deque" << std::endl;
	for(deque::reverse_iterator  it = deq.rbegin(); it != deq.rend(); ++it) {
		std::cout << ", " << *it;
	}
	return(0);
}

