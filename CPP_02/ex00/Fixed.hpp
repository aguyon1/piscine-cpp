/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:38:56 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/20 10:58:27 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed
{
	private:
		int _rawBits;
		static const int _nbFracBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		Fixed& operator=(const Fixed& other);
};

#endif
