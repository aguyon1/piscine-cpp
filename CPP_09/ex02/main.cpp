/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:03:38 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/27 19:41:15 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <errno.h>
#include <string.h>
#include <functional>
#include <sys/time.h>
#include <iomanip>

unsigned long myStrtoul(const char *str)
{
	unsigned long n;

	n = strtoul(str, NULL, 10);
	if (!all_of(str, str + strlen(str), isdigit))
		throw std::runtime_error("input is not an integer");
	if (errno == ERANGE)
		throw std::runtime_error("input is out of range");
	return (n);
}

int main(int argc, char *argv[])
{
	clock_t start, end;
	double time_taken;

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

	start = clock();
	mergeInsertSort(vec.begin(), vec.end());
	end = clock();

	time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000.0;
    std::cout << "Time taken by program is : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " us " << std::endl;

	start = clock();
	mergeInsertSort(lst.begin(), lst.end());
	end = clock();

	time_taken = static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC) * 1000000.0;
    std::cout << "Time taken by program is : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " us " << std::endl;

	std::cout << std::boolalpha << is_sorted(vec.begin(), vec.end(), std::less<unsigned long>());

	return (0);
}