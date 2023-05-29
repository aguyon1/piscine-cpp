/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:37:15 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/24 11:52:33 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Random.hpp"
#include <iostream>

Random::Random() : _seed(0)
{
	if (_seed == 0)
		_seed = time(NULL);
	randomize();
}

Random::~Random(){}

void Random::reset_seed(unsigned long seed)
{
	_seed = seed;
	if (seed == 0)
		_seed = time(NULL);
	randomize();
}

int Random::integer(unsigned long lo, unsigned long hi)
{
	randomize();
	return ((_seed/10)%(hi-lo+1) + lo);
}

double Random::real()
{
	randomize();
	return (static_cast<double>(_seed)/ULONG_MAX);
}

void Random::randomize()
{
	_seed = (1103515245*_seed+123456789)%ULONG_MAX;
}