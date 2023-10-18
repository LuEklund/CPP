/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:31:21 by leklund           #+#    #+#             */
/*   Updated: 2023/10/12 17:31:23 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <iostream>
# include <climits>

enum	ERROR
{
	OK,
	NO_SPACE,
	INVALID_CHAR,
	INSUFFICIENT_VALUES,
	INVALID_END,
	DIVISION_BY_ZERO,
	OVERFLOW
};

class RPN
{
private:
	std::stack<int> myStack;

	RPN(const RPN& copy);
	RPN &operator=(const RPN &copy);

	int	fetchValues(int *first, int *second);
	int	result(char sign, long long int *value);
	int	assign(unsigned char c);

public:
	RPN();
	~RPN();

	int	calculate(std::string input);

};



#endif
