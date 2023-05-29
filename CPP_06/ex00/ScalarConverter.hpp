/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:20:02 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/24 09:34:04 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include "utils.hpp"
#include "MyVector/MyVector.hpp"
#include <iostream>
#include <cmath>

struct S
{
	bool (*predicate)(const std::string& s);
	std::string message;
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);

		static bool is_char(const std::string& s);
		static bool is_signed(const std::string& s);
		static bool is_float(const std::string& s);
		static bool is_double(const std::string& s);
		static bool is_unsigned(const std::string& s);
		static bool is_special_value(const std::string& s);
		static int stoi(const std::string& s);
		static const std::string special_values[3];
	public:
		static void convert(const std::string& s);
};

template<typename T>
static void print_conversion(T t)
{

	std::cout << "char: ";
	try
	{
		if (std::isnan(t) || std::isinf(t))
			throw std::runtime_error("impossible");
		char c = narrow_cast<char, T>(t);
		if (!isprint(c))
			throw std::runtime_error("Non displayable");
		std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "int: ";
	try
	{
		if (std::isnan(t) || std::isinf(t))
			throw std::runtime_error("impossible");
		int i = narrow_cast<int, T>(t);
		std::cout << i;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: ";
	try
	{
		float f = narrow_cast<float, T>(t);
		std::cout << f << 'f';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "double: ";
	try
	{
		double d = narrow_cast<double, T>(t);
		std::cout << d;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
}

#endif