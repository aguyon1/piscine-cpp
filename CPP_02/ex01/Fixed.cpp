/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:46:51 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/21 14:54:55 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << Fixed::_nbFracBits;
	return;
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(x * (1 << Fixed::_nbFracBits));
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(_rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
	return;
}

float	Fixed::toFloat(void) const
{
	return((float)_rawBits / (float)(1 << Fixed::_nbFracBits));
}

int		Fixed::toInt(void) const
{
	return(_rawBits >> Fixed::_nbFracBits);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = other.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& number)
{
	return(os << number.toFloat());
}
