/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:36:57 by leklund           #+#    #+#             */
/*   Updated: 2023/04/05 06:37:00 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	stringIndex;
	
	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	while (argv[i])
		{
			stringIndex = 0;
			while(argv[i][stringIndex])
			{
				if(argv[i][stringIndex] >= 'a' && argv[i][stringIndex] <= 'z')
					std::cout << (unsigned char)toupper((argv[i][stringIndex]));
				else
					std::cout << argv[i][stringIndex];
				stringIndex++;
			}
			i++;
			if (argv[i])
				std::cout << " ";
			else
				std::cout << std::endl;
		}
	return (0);
}