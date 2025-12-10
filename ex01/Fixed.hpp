/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:06:39 by lenakach          #+#    #+#             */
/*   Updated: 2025/12/10 15:45:48 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
// pour std
#include <iostream>
// pour roundf
#include <cmath>

class Fixed
{
  private:
	int _fixedValue;
	static const int _rawBits = 8;

  public:
	// Constructeur default.
	Fixed(void);
	// Constructeur copie
	Fixed(const Fixed &other);
	// Constructeur avec valeur specialisee
	Fixed(int const value);
	// Constructeur pour convertir float en pas de virgule
	Fixed(float const value);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);
