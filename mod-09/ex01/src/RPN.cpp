/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:31:29 by leklund           #+#    #+#             */
/*   Updated: 2023/10/12 17:31:31 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

};

RPN::~RPN()
{

};

int	RPN::fetchValues(int *first, int *second)
{
	if (myStack.size() < 2)
		return (INSUFFICIENT_VALUES);
	else
	{
		*first = myStack.top();
		myStack.pop();
		*second = myStack.top();
		myStack.pop();
	}
	return (OK);
}

int	RPN::assign(unsigned char c)
{
	int	first;
	int	second;
	if (c == '+')
	{
		if (fetchValues(&first, &second) != OK)
			return (INSUFFICIENT_VALUES);
		myStack.push(second + first);
		if ((first > 0 && second > 0 && myStack.top() < 0)
		||	(first < 0 && second < 0 && myStack.top() > 0))
			return(OVERFLOW);
	}
	else if (c == '-')
	{
		if (fetchValues(&first, &second) != OK)
			return (INSUFFICIENT_VALUES);
		myStack.push(second - first);
		if (((-1 * first) > 0 && second > 0 && myStack.top() < 0)
		||	((-1 * first) < 0 && second < 0 && myStack.top() > 0))
			return(OVERFLOW);
	}
	else if (c == '/')
	{
		if (fetchValues(&first, &second) != OK)
			return (INSUFFICIENT_VALUES);
		else if(first == 0)
			return (DIVISION_BY_ZERO);
		else if(second == INT_MIN && first == -1)
			return(OVERFLOW);
		myStack.push(second / first);
	}
	else if (c == '*')
	{
		if (fetchValues(&first, &second) != OK)
			return (INSUFFICIENT_VALUES);
		myStack.push(second * first);
		if((second == INT_MIN && first == -1)
		||	(first == INT_MIN && second == -1)
		||	(first > 0 && second > 0 && myStack.top() < 0)
		||	(first < 0 && second < 0 && myStack.top() > 0)
		||	(first < 0 && second > 0 && myStack.top() > 0)
		||	(first > 0 && second < 0 && myStack.top() > 0))
			return(OVERFLOW);
	}
	else
		myStack.push((c - '0'));
	return(OK);
};


int	RPN::calculate(std::string input)
{
	unsigned int	len = input.length();
	int				ret;

	for (unsigned int i = 0; i < len; i++)
	{
		while(i < len && input[i] == ' ')
			i++;
		if(i < len)
		{
			if (!isdigit(input[i]) && !(input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*'))
				return(INVALID_CHAR);
			if ((ret = assign(input[i])) != OK)
				return (ret);
			if (i+1 < len && input[i+1] != ' ')
				return (NO_SPACE);
		}
	}
	if(myStack.size() != 1)
		return (INVALID_END);
	std::cout << myStack.top() << std::endl;
	return (0);
};
