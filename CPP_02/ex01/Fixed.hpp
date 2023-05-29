/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:38:56 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/21 14:48:54 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"
#include <cmath>

class Fixed
{
	private:
		int _rawBits;
		static const int _nbFracBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int n);
		Fixed(const float x);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed& operator=(const Fixed& other);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& number);

#endif
