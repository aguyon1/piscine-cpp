/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:09:00 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/24 16:25:26 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

const std::string ScalarConverter::special_values[3] = {"-inf", "inf", "nan"};

bool ScalarConverter::is_special_value(const std::string& s)
{
	return (find(&special_values[0], &special_values[3], s) != &special_values[3]);
}

bool ScalarConverter::is_unsigned(const std::string& s)
{
	return (!s.empty() && all_of(s.begin(), s.end(), isdigit));
}

bool ScalarConverter::is_char(const std::string& s)
{
	return(s.length() == 1);
}

bool ScalarConverter::is_signed(const std::string& s)
{
	if (s.empty() || s == "-")
		return (false);
	return (is_unsigned(std::string(s[0] == '-' ? s.begin() + 1 : s.begin(), s.end())));
}

bool ScalarConverter::is_float(const std::string& s)
{
	const size_t len = s.length();

	return (!s.empty() && is_double(std::string(s, 0, len - 1)) && s[len - 1] == 'f');
}

bool ScalarConverter::is_double(const std::string& s)
{
	if (is_special_value(s))
		return (true);
	MyVector<std::string> vec = split(s, '.');

	return (vec.size() == 2 && is_signed(vec[0]) && is_unsigned(vec[1]));
}

int ScalarConverter::stoi(const std::string& s1)
{
	std::stringstream ss1(s1), ss2;
	std::string s2;
	int res;
	size_t i;

	ss1 >> res;
	ss2 << res;

	s2 = ss2.str();
	for (i = 0; i < s2.length() && isspace(s2[i]); i++)
		;
	if (s2.compare(i, s1.length(), s1) != 0)
		throw std::rutime_error("Int overflow/underflow");
	return (res);
}

void ScalarConverter::convert(const std::string& s)
{
	if (is_char(s))
	{
		std::cout << "//Input is char" << std::endl << std::endl;
		print_conversion(s[0]);
	}
	else if (is_signed(s))
	{
		try
		{
			int n = stoi(s);
			std::cout << "//Input is int" << std::endl << std::endl;
			print_conversion(n);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else if (is_float(s))
	{
		std::cout << "//Input is float" << std::endl << std::endl;
		print_conversion(std::strtof(s.c_str(), NULL));
	}
	else if (is_double(s))
	{
		std::cout << "//Input is double" << std::endl << std::endl;
		print_conversion(std::strtod(s.c_str(), NULL));
	}
	else
	{
		std::cout << "Unknown type" << std::endl;
	}
}