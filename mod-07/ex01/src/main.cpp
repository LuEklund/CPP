/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:09:09 by leklund           #+#    #+#             */
/*   Updated: 2023/08/18 10:09:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


void	multiplier(int	value)
{
	std::cout << "Value " << value << " * 2 = " << value*2 << std::endl;
	return;
}

int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	iter(a, 10, multiplier);
	return(0);
}