/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:17:59 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/22 14:10:57 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
inline void	swap(T& a, T& b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
inline T&	min(const T& a, const T& b)
{
	return const_cast< T& >(a < b ? a : b);
}

template <typename T>
inline T&	max(const T& a, const T& b)
{
	return const_cast< T& >(a > b ? a : b);
}

#endif
