/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:35:43 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/25 13:19:48 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
	: _maxSize(N)
{}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span(){}

Span& Span::operator=(const Span& other)
{
	_set = other._set;
	return (*this);
}

void Span::addNumber(int n)
{
	if (_set.size() == _maxSize)
		throw std::length_error("Span is full");
	_set.insert(n);
}

void Span::checkSpan() const
{
	if (_set.size() <= 1)
		throw std::logic_error("not enought elements");
}

unsigned int Span::shortestSpan() const
{
	checkSpan();
	std::vector<unsigned int> vec;

	vec.reserve(_set.size());
	std::adjacent_difference(_set.begin(), _set.end(), std::back_inserter(vec));
	vec.erase(vec.begin());
	return(*(std::min_element(vec.begin(), vec.end())));
}

unsigned int Span::longestSpan() const
{
	checkSpan();

	return (*(_set.rbegin()) - *(_set.begin()));
}