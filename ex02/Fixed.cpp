/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:56:06 by lenakach          #+#    #+#             */
/*   Updated: 2025/12/10 18:22:41 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//min functions
Fixed	&Fixed::min(Fixed &other1, Fixed &other2)
{
	if (other1.getRawBits() < other2.getRawBits())
		return other1;
	return other2;
}

Fixed	&Fixed::min(const Fixed &other1, const Fixed &other2)
{
	if (other1.getRawBits() < other2.getRawBits())
		return const_cast<Fixed&>(other1);
	return const_cast<Fixed&>(other2);
}

//Max functions
Fixed	&Fixed::max(Fixed &other1, Fixed &other2)
{
	if (other1.getRawBits() > other2.getRawBits())
		return (other1);
	return (other2);
}

Fixed	&Fixed::max(const Fixed &other1, const Fixed &other2)
{
	if (other1.getRawBits() > other2.getRawBits())
		return const_cast<Fixed&>(other1);
	return const_cast<Fixed&>(other2);
}

//operateur pre incr et pre decr
Fixed	&Fixed::operator++()
{
	_fixedValue += 1;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	_fixedValue -= 1;
	return (*this);
}

//operateur post incr et post decr
Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	_fixedValue += 1;
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;
	_fixedValue -= 1;
	return temp;
}

//operateurs arithmetiques
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(_fixedValue + other.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(_fixedValue - other.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(_fixedValue * other.getRawBits() >> _rawBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits((_fixedValue << _rawBits) / other.getRawBits());
	return result;
}

//Operateurs de comparaison
bool Fixed::operator==(const Fixed &other) const
{
	return (_fixedValue == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_fixedValue != other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_fixedValue < other.getRawBits());
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (_fixedValue > other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_fixedValue <= other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_fixedValue >= other.getRawBits());
}

int Fixed::getRawBits(void) const
{
	return (_fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedValue = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedValue) / (1 << _rawBits);
}

int	Fixed::toInt(void) const
{
	return _fixedValue >> _rawBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	std::cout << "To float:" << std::endl;
    out << fixed.toFloat();  // Affiche la valeur flottante
    return out;
}

//Constructeurs && destructeurs
Fixed::Fixed(void)
{
	_fixedValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixedValue = other.getRawBits();
	return (*this);
}

Fixed::Fixed (int const value)
{
	_fixedValue = value << _rawBits;
}

Fixed::Fixed(float const value)
{
	_fixedValue = roundf(value * (1 << _rawBits));
}

Fixed::~Fixed(void)
{
}
