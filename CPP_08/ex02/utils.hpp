/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:21:59 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 09:47:57 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
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

struct IsEvenFunctor
{
	bool operator()(int n) {return (n % 2 == 0);}
};

struct MulTwoFunctor
{
	int operator()(int n){return (n<<1);}
};

#endif