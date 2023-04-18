/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 06:35:22 by leklund           #+#    #+#             */
/*   Updated: 2023/04/18 06:35:24 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HARL_HPP
# define HARL_HPP
# include <map>
# include <string>

class Harl
{
private:
	void		debug( void );
	void 		info( void );
	void		warning( void );
	void 		error( void );
	std::string	_levels[4];
	void		(Harl::*_functions[4])(void);
public:
	~Harl();
	void complain(std::string level );
	Harl();
};


#endif
