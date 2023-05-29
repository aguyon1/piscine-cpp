/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:33:58 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/25 09:14:23 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <iostream>

//Fibonacci sequence : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
//Tribonacci sequence : 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504

int main(void)
{
	std::cout << "//Tests with vector" << std::endl;
	std::vector<int> vec(13);
	std::generate(vec.begin(), vec.end(), FibonacciFunctor());
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	printExistence(vec, 21, "vector");
	printExistence(vec, 42, "vector");
	std::cout << std::endl;

	std::cout << "//Tests with deque" << std::endl;
	std::deque<int> deq(13);
	std::generate(deq.begin(), deq.end(), FibonacciFunctor());
	std::for_each(deq.begin(), deq.end(), PrintFunctor()), std::cout << std::endl;
	printExistence(deq, 89, "deque");
	printExistence(deq, 42, "deque");
	std::cout << std::endl;

	std::cout << "//Tests with list" << std::endl;
	std::list<int> lst(13);
	std::generate(lst.begin(), lst.end(), TribonacciFunctor());
	for (std::list<int>::const_iterator cit = lst.begin(); cit != lst.end(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;
	printExistence(lst, 44, "list");
	printExistence(lst, 42, "list");
	std::cout << std::endl;

	std::cout << "//Tests with multiset" << std::endl;
	std::list<int> myset(13);
	std::generate(myset.begin(), myset.end(), TribonacciFunctor());
	std::copy(myset.begin(), myset.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
	printExistence(myset, 504, "multiset");
	printExistence(myset, 42, "multiset");
	std::cout << std::endl;
	return (0);
}