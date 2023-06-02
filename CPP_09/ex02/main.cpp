/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:03:38 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/31 13:23:26 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <errno.h>
#include <string.h>
#include <functional>
#include <ctime>

unsigned long myStrtoul(const char *str)
{
	unsigned long n;

	n = strtoul(str, NULL, 10);
	if (!all_of(str, str + strlen(str), isdigit))
		throw std::runtime_error(str + std::string(" is not a positive integer"));
	if (errno == ERANGE)
		throw std::overflow_error(str + std::string(" is out of range"));
	return (n);
}

void printExecutionTime(const clock_t& start, const clock_t& end, unsigned int nb_elem, const std::string& container_name)
{
	std::cout << "Time to process a range of " << nb_elem << " elemtents with std::" << container_name << " : ";
	std::cout << std::fixed << (end - start) / (double)CLOCKS_PER_SEC << " sec" << std::endl;
}

int main(int argc, char *argv[])
{
	clock_t start, end;

	std::vector<unsigned long> vec(argc - 1);
	try
	{
		std::transform(argv + 1, argv + argc, vec.begin(), myStrtoul);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return (1);
	}
	std::list<unsigned long> lst(vec.begin(), vec.end());
	std::deque<unsigned long> deq(vec.begin(), vec.end());

	//Vector sort
	std::cout << "Before:   ";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<unsigned long>(std::cout, " ")), std::cout << std::endl;
	start = clock();
	mergeInsertSort(vec.begin(), vec.end());
	end = clock();
	std::cout << "After:   ";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<unsigned long>(std::cout, " ")), std::cout << std::endl;
	printExecutionTime(start, end, vec.size(), "vector");

	//List sort
	start = clock();
	mergeInsertSort(lst.begin(), lst.end());
	end = clock();
	printExecutionTime(start, end, lst.size(), "list");

	//Dequeue sort
	start = clock();
	mergeInsertSort(deq.begin(), deq.end());
	end = clock();
	printExecutionTime(start, end, deq.size(), "deque");

	std::cout << std::boolalpha;
	std::cout << "std::vector is sorted : " << is_sorted(vec.begin(), vec.end(), std::less<unsigned long>()) << std::endl;
	std::cout << "std::list is sorted : " << is_sorted(lst.begin(), lst.end(), std::less<unsigned long>()) << std::endl;
	std::cout << "std::deque is sorted : " << is_sorted(deq.begin(), deq.end(), std::less<unsigned long>()) << std::endl;

	return (0);
}