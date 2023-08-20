/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <leklund@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:45:57 by leklund           #+#    #+#             */
/*   Updated: 2023/08/19 10:46:02 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>

struct Data
{
	int val;
	char c;
};


class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer &);
	~Serializer();
	
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif

