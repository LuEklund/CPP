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
# include <ctime>

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
	static const int		segmentSize = 5;

	PmergeMe(const PmergeMe& copy);
	PmergeMe &operator=(const PmergeMe &copy);

	int	ft_stoi(std::string value);

	void	sortVector(int start, int end);
	void	insertionSortVector(int start, int end);
	void	mergeVector(int curPos, int newPos, int maxLen);
	
	void	sortDeque(int start, int end);
	void	insertionSortDeque(int start, int end);
	void	mergeDeque(int curPos, int newPos, int maxLen);

	void	displayVec();
	void	displayDeq();

public:
	PmergeMe();
	~PmergeMe();

	int	saveValidInput(int argc, char **argv);
	int	action();
};



#endif
