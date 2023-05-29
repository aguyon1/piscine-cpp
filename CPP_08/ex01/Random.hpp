/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:36:55 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/25 12:41:39 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <ctime>
#include <climits>

class Random
{
public:
	Random();
	Random(const Random& other);
	Random& operator=(const Random& other);
	~Random();
	void reset_seed(unsigned long=0);
	int integer(unsigned long,unsigned long);
	double real();
private:
	unsigned long _seed;
	void randomize();
};

#endif