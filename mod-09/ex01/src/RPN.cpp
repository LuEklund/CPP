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

int	RPN::result(char sign, long long int *value)
{
	int	first;
	int	second;

	if (fetchValues(&first, &second) != OK)
		return (INSUFFICIENT_VALUES);
	switch (sign)
	{
	case '+' :
		*value = static_cast<long long int>(second) + static_cast<long long int>(first);
		break;
	case '-' :
		*value = static_cast<long long int>(second) - static_cast<long long int>(first);
		break;
	case '*' :
		*value = static_cast<long long int>(second) * static_cast<long long int>(first);
		break;
	case '/' :
		if(first == 0)
			return (DIVISION_BY_ZERO);
		*value = static_cast<long long int>(second) / static_cast<long long int>(first);
		break;
	default:
		break;
	}
	if (*value < INT_MIN || *value > INT_MAX)
		return(OVERFLOW);
	return (OK);
}

int	RPN::assign(unsigned char c)
{
	long long int	value;
	int				res;

	if(c == '+' || c == '-' || c == '/' || c == '*')
	{
		if((res = result(c, &value)) != OK)
			return (res);
		myStack.push(value);
	}
	else
		myStack.push((c - '0'));
	return(OK);
};


int	RPN::calculate(std::string input)
{
	unsigned int	len = input.length();
	int				ret;

	//-2147483648 and 2147483647
	// myStack.push(2147483647);
	// myStack.push(2147483647);
	// myStack.push(-2147483648);
	// myStack.push(-2147483648);

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
