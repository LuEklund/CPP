/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:37:56 by leklund           #+#    #+#             */
/*   Updated: 2023/04/05 14:37:58 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
class Contact
{
private:
	std::string 	fName;
	std::string 	lName;
	std::string 	Nname;
	std::string		Number;
	std::string		Secret;
public:
	int	update(std::string &fname,
				std::string &lName,
				std::string &Nname,
				std::string &Number,
				std::string &Secret);
	int	displayInfo();
	int	displayFull();
	Contact();
	~Contact();
};




#endif

