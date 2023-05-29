/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:29:05 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/25 09:13:09 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>

class FibonacciFunctor
{
public:
	FibonacciFunctor() : _a(0), _b(1){}
	int operator()()
	{
		int tmp = _a;
		_a = _b;
		_b += tmp;
		return (tmp);
	};
private:
	int _a, _b;
};

class TribonacciFunctor
{
public:
	TribonacciFunctor() : _a(0), _b(1), _c(1){}
	int operator()()
	{
		int tmpa = _a, tmpb = _b;
		_a = _b;
		_b = _c;
		_c += tmpa + tmpb;
		return (tmpa);
	};
private:
	int _a, _b, _c;
};

struct PrintFunctor
{
	void operator()(const int& n)
	{
		std::cout << n << " ";
	};
};

template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	return (std::find(container.begin(), container.end(), value));
}

template<typename T>
bool is_inside(const T& container, int value)
{
	return (easyfind(container, value) != container.end());
}

template<typename T>
void printExistence(const T& container, int value, const std::string& container_name)
{
	std::cout << value << (is_inside(container, value) ? " is in " : " is not in ") << container_name << std::endl;
}

#endif