/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:25:16 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/25 13:09:21 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <set>
#include <vector>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& other);
	~Span();

	Span& operator=(const Span& other);
	void addNumber(int n);
	template<typename InputIt> void addRange(InputIt first, InputIt last);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
private:
	Span();
	void checkSpan() const;
private:
	std::multiset<int> _set;
	unsigned int _maxSize;

};

template<typename InputIt>
void Span::addRange(InputIt first, InputIt last)
{
	if (_set.size() + std::distance(first, last) > _maxSize)
		throw std::length_error("Try to insert too much elements");
	_set.insert(first, last);
}

#endif