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

#include "Serializer.hpp"

int main()
{
	Data test;
	test.val = 10;
	test.c = 'a';
	uintptr_t res = Serializer::serialize(&test);
	Data *test2 = Serializer::deserialize(res);
	std::cout << test2->val << " " << test2->c << std::endl;
	return(0);
}