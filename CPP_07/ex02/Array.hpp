/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:37:34 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/22 23:12:39 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename ELEMENT>
class Array
{
	private:
		ELEMENT *_array;
		unsigned int _size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array<ELEMENT>& other);
		~Array();

		ELEMENT& operator[](unsigned int pos) const;
		unsigned int size(void) const;
};

template <typename ELEMENT>
std::ostream& operator<<(std::ostream& os, const Array<ELEMENT>& array);

#include "Array.tpp"

#endif
