/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:02:36 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/22 18:22:00 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void	iter(T *array, size_t size, F f)
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}


template <typename T>
void	print(const T& elem)
{
	std::cout << elem << ", ";
}

#endif
