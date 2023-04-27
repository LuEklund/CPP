/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:18:18 by leklund           #+#    #+#             */
/*   Updated: 2023/04/18 10:18:19 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

int main( void ) {
	Point a(0, 0);
	Point b(40, 0);
	Point c(20, 30);
	Point p(20, 29);
	if (bsp(a, b, c, p)) {
        std::cout << "Point P is inside the triangle ABC" << std::endl;
    } else {
        std::cout << "Point P is outside the triangle ABC" << std::endl;
    }
	return (0);
}
