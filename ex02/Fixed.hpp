/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:34:55 by lenakach          #+#    #+#             */
/*   Updated: 2025/12/10 18:18:03 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int	_fixedValue;
		int	_rawBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other) ;
		Fixed(int const value);
		Fixed(float const value);
		~Fixed(void);
		int	getRawBits(void) const;
		void	setRawBits(int const value);
		float	toFloat(void) const;
		int	toInt(void) const;
		//Operateurs de comparaison
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		//operateurs arithmetiques
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		//operateurs incrementation
		Fixed	&operator++();
		Fixed	operator++(int);		
		Fixed	&operator--();
		Fixed	operator--(int);
		//Min functions
		static	Fixed &min(Fixed &other1, Fixed &other2);
		static	Fixed &min(const Fixed &other1, const Fixed &other2);
		//Max functions
		static Fixed &max(Fixed	&other1, Fixed &other2);
		static Fixed &max(const Fixed &other1, const Fixed &other2);
		
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);
