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
	}
	return (OK);
}



void	PmergeMe::insertionSortVector(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		int moveValue = vec[i + 1];
		int cmpIndex = i + 1;
		while (cmpIndex > start && vec[cmpIndex - 1] > moveValue)
		{
			vec[cmpIndex] = vec[cmpIndex - 1];
			cmpIndex--;
		}
		vec[cmpIndex] = moveValue;
	}
};


void	PmergeMe::mergeVector(int startPos, int middle, int endPos)
{
	int	maxLeftIndex = middle - startPos + 1;
	int	maxRightIndex = endPos - middle;

	// std::cout << "maxLeftIndex["<< maxLeftIndex <<"], maxRightIndex["<< maxRightIndex <<"]" << std::endl;

	vector leftSide(vec.begin() + startPos, vec.begin() + middle + 1);
	vector rightSide(vec.begin() + middle + 1, vec.begin() + endPos + 1);

	int	rightIndex = 0;
	int leftIndex = 0;
	int i = startPos;

    while (leftIndex < maxLeftIndex && rightIndex < maxRightIndex) {
        if (leftSide[leftIndex] <= rightSide[rightIndex]) {
            vec[i] = leftSide[leftIndex];
            leftIndex++;
        } else {
            vec[i] = rightSide[rightIndex];
            rightIndex++;
        }
        i++;
    }

    while (leftIndex < maxLeftIndex) {
        vec[i] = leftSide[leftIndex];
        leftIndex++;
        i++;
    }

    while (rightIndex < maxRightIndex) {
        vec[i] = rightSide[rightIndex];
        rightIndex++;
        i++;
    }

};

void	PmergeMe::sortVector(int curPos, int maxLen)
{
	// displayVec();
	if (maxLen - curPos > segmentSize)
	{
		int	newPos = (curPos + maxLen) / 2;
		
		sortVector(curPos, newPos);
		sortVector(newPos + 1, maxLen);
		// std::cout << "===================[merge curPos["<<curPos<<"] newPos["<<newPos<<"] maxLen["<<maxLen<<"]]====================" << std::endl;
		// displayVec();
		mergeVector(curPos, newPos, maxLen);
		// std::cout << "===============[AFTER]===============" << std::endl;
		// displayVec();
	}
	else
	{
		// std::cout << "===================[insertsort curPos["<<curPos<<"] maxLen["<<maxLen<<"]]====================" << std::endl;
		// displayVec();
		insertionSortVector(curPos, maxLen);
		// std::cout << "===============[AFTER]===============" << std::endl;
		// displayVec();

	}
};

void	PmergeMe::insertionSortDeque(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		int moveValue = deq[i + 1];
		int cmpIndex = i + 1;
		while (cmpIndex > start && deq[cmpIndex - 1] > moveValue)
		{
			deq[cmpIndex] = deq[cmpIndex - 1];
			cmpIndex--;
		}
		deq[cmpIndex] = moveValue;
	}
};

void	PmergeMe::mergeDeque(int startPos, int middle, int endPos)
{
	int	maxLeftIndex = middle - startPos + 1;
	int	maxRightIndex = endPos - middle;

	deque leftSide(deq.begin() + startPos, deq.begin() + middle + 1);
	deque rightSide(deq.begin() + middle + 1, deq.begin() + endPos + 1);

	int	rightIndex = 0;
	int leftIndex = 0;
	int i = startPos;

	while (leftIndex < maxLeftIndex && rightIndex < maxRightIndex) {
		if (leftSide[leftIndex] <= rightSide[rightIndex]) {
			deq[i] = leftSide[leftIndex];
			leftIndex++;
		} else {
			deq[i] = rightSide[rightIndex];
			rightIndex++;
		}
		i++;
	}

	while (leftIndex < maxLeftIndex) {
		deq[i] = leftSide[leftIndex];
		leftIndex++;
		i++;
	}

	while (rightIndex < maxRightIndex) {
		deq[i] = rightSide[rightIndex];
		rightIndex++;
		i++;
	}
};

void	PmergeMe::sortDeque(int curPos, int maxLen)
{
	if (maxLen - curPos > segmentSize)
	{
		int	newPos = (curPos + maxLen) / 2;
		
		sortDeque(curPos, newPos);
		sortDeque(newPos + 1, maxLen);
		mergeDeque(curPos, newPos, maxLen);
	}
	else
	{
		insertionSortDeque(curPos, maxLen);
	}
};


//2147483647, -2147483648
int	PmergeMe::action()
{
	std::clock_t startVec, startDeq, endVec, endDeq; 
	double	time;

	std::cout << "Before: ";
	displayVec();

	startVec = std::clock();
	sortVector(0, vec.size() - 1);
	endVec = std::clock();

	startDeq = std::clock();
	sortDeque(0, deq.size() - 1);
	endDeq = std::clock();

	std::cout << "After: ";
	displayDeq();

	time = double(endVec - startVec) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << (time * 1000) << " ms" << std::endl;
	time = double(endDeq - startDeq) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << (time * 1000) << " ms" << std::endl;
	return(0);
}

void	PmergeMe::displayVec()
{
	for(vector::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
};

void	PmergeMe::displayDeq()
{
	for(deque::iterator  it = deq.begin(); it != deq.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
};