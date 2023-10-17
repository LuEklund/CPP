/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:09:08 by leklund           #+#    #+#             */
/*   Updated: 2023/10/12 22:09:10 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <sstream>

enum RESULT
{
	OK,
	INAVLID_VALUE

};

typedef std::deque<int>		deque;
typedef std::vector<int>	vector;

class PmergeMe
{
private:
	deque	deq;
	vector	vec;
	unsigned int		size;

	PmergeMe(const PmergeMe& copy);
	PmergeMe &operator=(const PmergeMe &copy);

	int	ft_stoi(std::string value);

public:
	PmergeMe();
	~PmergeMe();

	int	saveValidInput(int argc, char **argv);
	int	action();
};



#endif
