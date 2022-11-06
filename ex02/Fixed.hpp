/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:56:54 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/06 12:56:23 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);

	Fixed			&operator=(const Fixed &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool operator>(const Fixed &rhs);
	bool operator<(const Fixed &rhs);
	bool operator>=(const Fixed &rhs);
	bool operator<=(const Fixed &rhs);
	bool operator==(const Fixed &rhs);
	bool operator!=(const Fixed &rhs);

	Fixed operator+(const Fixed &rhs);
	Fixed operator-(const Fixed &rhs);
	Fixed operator*(const Fixed &rhs);
	Fixed operator/(const Fixed &rhs);

	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &rhs);

#endif
