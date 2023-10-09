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

#include "Array.hpp"

#define SIZE 4
int main()
{
	{
		Array<int> array(SIZE);
		std::cout << "Size of array " << array.size() << std::endl;
		std::cout << "=================[DEFAULT ARRAY]==================" << std::endl;
		for(int i = 0; i < SIZE; i++)
		{
			std::cout << "array["<< i <<"] = " << array[i] << std::endl;
		}
		std::cout << "=================[DEFAULT ARRAY ASSIGN VALUES]==================" << std::endl;
		for(int i = 0; i < SIZE; i++)
		{
			array[i] = i;
			std::cout << "array["<< i <<"] = " << array[i] << std::endl;
		}
		Array<int> array2(array);
		std::cout << "=================[COPY CONSTRUCTOR ARRAY]==================" << std::endl;
		for(int i = 0; i < SIZE; i++)
		{
			std::cout << "array2["<< i <<"] = " << array2[i] << std::endl;
		}
		std::cout << "=================[CHANGE VALUES (DEEP COPY)]==================" << std::endl;
		array[0] = -100000;
		array2[2] = 100000;
		for(int i = 0; i < SIZE; i++)
		{
			std::cout << "array["<< i <<"] = " << array[i] << std::endl;
		}
		std::cout << "------------------------------------" << std::endl;
		for(int i = 0; i < SIZE; i++)
		{
			std::cout << "array2["<< i <<"] = " << array2[i] << std::endl;
		}
		std::cout << "=================[COPY ASSIGNEMNT OPERATOR]==================" << std::endl;
		array2[1] = 500;
		array = array2;
		for(int i = 0; i < SIZE; i++)
		{
			std::cout << "array["<< i <<"] = " << array[i] << std::endl;
		}
		std::cout << "=================[EXCEPTIONS]==================" << std::endl;
		try
		{
			std::cout << array[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "NEG Invalid index: " << e.what() << std::endl;
		}
		try
		{
			array[SIZE] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "MAX Invalid index: " << e.what() << std::endl;
		}
		Array<int> empty;
		try
		{
			std::cout << empty[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Empty Invalid index: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "=================[COMPLEX TYPE]==================" << std::endl;
		Array<std::string> complex(SIZE);

		complex[0] = "One";
		complex[1] = "Two";
		complex[2] = "Thee";
		complex[3] = "Four";
		for(int i = 0; i < SIZE; i++)
		{
			std::cout << "array["<< i <<"] = " << complex[i] << std::endl;
		}
		std::cout << "------------------------------------" << std::endl;
		complex[2] = "Fortytwo";
		for(int i = 0; i < SIZE; i++)
		{
			std::cout << "array["<< i <<"] = " << complex[i] << std::endl;
		}
	}
		
	return(0);
}