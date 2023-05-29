/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:44:54 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/25 13:22:39 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "utils.hpp"
#include <limits>
#include <iostream>
#include <vector>

int main()
{
	//Test 1 s
	std::cout << "//Test 1" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	////

	//Test 2
	std::cout << "//Test 2" << std::endl;

	std::vector<int> vec2(20);
	std::generate(vec2.begin(), vec2.end(), RandomGeneratorFunctor(1, 100));
	// print(vec2.begin(), vec2.end()), std::cout << std::endl;

	Span sp2(20);
	sp2.addRange(vec2.begin(), vec2.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << std::endl;
	////

	//Test 3
	std::cout << "//Test 3" << std::endl;

	std::vector<int> vec3(10000);
	std::generate(vec3.begin(), vec3.end(), RandomGeneratorFunctor(1, UINT_MAX));
	// print(vec3.begin(), vec3.end()), std::cout << std::endl;

	Span sp3(10000);
	sp3.addRange(vec3.begin(), vec3.end());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return 0;
}