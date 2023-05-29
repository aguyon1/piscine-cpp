/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:02:40 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/24 08:40:43 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include "MyVector/MyVector.hpp"
#include <iostream>
#include <cmath>

MyVector<std::string> split(const std::string& input, char sep);

template<typename InputIt, typename UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
	for (;first!=last;++first)
		if (!p(*first))
			return (false);
	return (true);
}

template<typename InputIt, typename T>
InputIt find(InputIt first, InputIt last, const T& value)
{
	for (; first != last; ++first)
		if (*first == value)
			return (first);
	return (last);
}

template<class Target, class Source>
Target narrow_cast(Source v)
{
	if (isnan(v))
		return (v);
	Target r = static_cast<Target>(v);
	if (static_cast<Source>(r) != v)
		throw std::runtime_error("impossible");
	return (r);
}
#endif