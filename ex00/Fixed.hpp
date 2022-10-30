/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:56:54 by aaguiler          #+#    #+#             */
/*   Updated: 2022/10/30 20:12:32 by aaguiler         ###   ########.fr       */
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
	~Fixed(void);

	Fixed	&operator=(const Fixed &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

#endif
