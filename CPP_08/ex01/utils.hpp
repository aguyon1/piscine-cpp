/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:34 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/25 12:53:00 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "Random.hpp"
#include <iterator>
#include <algorithm>
#include <iostream>

struct RandomGeneratorFunctor
{
	RandomGeneratorFunctor(int lo, int hi) : _lo(lo), _hi(hi), _random(Random()){}
	int operator()(){return (_random.integer(_lo, _hi));}
	unsigned long _lo, _hi;
	Random _random;
};

template <typename InputIt>
void print(InputIt first, InputIt last)
{
	for (;first != last; ++first)
		std::cout << *first << " ";
}

#endif