/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:56:56 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/06 17:15:54 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int value)
{
	this->_value = (value << this->_fractionalBits);
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void)
{
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	this->_value = rhs.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &rhs)
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<(const Fixed &rhs)
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=(const Fixed &rhs)
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=(const Fixed &rhs)
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(const Fixed &rhs)
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(const Fixed &rhs)
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_value += (1 << this->_fractionalBits);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_value -= (1 << this->_fractionalBits);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	operator--();
	return (tmp);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float(this->_value) / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}
