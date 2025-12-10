/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:48:26 by lenakach          #+#    #+#             */
/*   Updated: 2025/12/10 17:54:52 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "AAAAAAAA" << std::endl;
	std::cout << a << std::endl;
	std::cout << "BBBBBBBB" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "CCCCCCC" << std::endl;
	std::cout << a << std::endl;
	std::cout << "DDDDDDD" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "EEEEE" << std::endl;
	std::cout << a << std::endl;

	std::cout << "on passe a b" << std::endl;
	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}