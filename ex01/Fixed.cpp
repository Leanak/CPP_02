/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:51:06 by lenakach          #+#    #+#             */
/*   Updated: 2025/12/10 13:53:41 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//toFloat
float	Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedValue) / (1 << _rawBits);
}

int	Fixed::toInt(void) const
{
	return _fixedValue >> _rawBits;
}
//operateur "<<" pour print le fixed_point number into the output stream
//mais en float
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();  // Affiche la valeur flottante
    return out;
}

//Getter
int	Fixed::getRawBits(void) const
{
	return (_fixedValue);
}

//Setter
void	Fixed::setRawBits(int const raw)
{
	_fixedValue = raw;
}

//Constructeur par defaut appele quand je cree une instance sans parametres.
//Ca va juste mettre ma fixedvalue a 0.
Fixed::Fixed(void)
{
	_fixedValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

//Constructeur de copie appele quand je creer une instance a partir d'une autre instance de meme type
//La fixedvalue sera herite de l'instance source
Fixed::Fixed(const Fixed &other)
{
	//Je peux aussi ne pas utiliser l'operateur "=" et mettre directement :
	// _fixedValue = other.getRawBits();
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

//Constructeur d'initialisation (ou de surcharge) est appele quand je donne une valeur
//specifique en parametre
Fixed::Fixed(int const value)
{
	_fixedValue = value;
	std::cout << "Int constructor called" << std::endl;
}

//Constructeur pour convertir un float en int
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedValue = roundf(value * (1 << _rawBits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
