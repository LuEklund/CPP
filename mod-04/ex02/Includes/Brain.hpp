/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 07:12:54 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 07:12:56 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain &);
	void setIdea(size_t index, std::string idea);
	std::string  getIdea(size_t index);
	~Brain();
};

#endif
