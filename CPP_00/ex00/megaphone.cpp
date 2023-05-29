/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:01:25 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 10:39:03 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string.h>

void print_str_upper(const std::string& str)
{
	for (std::string::const_iterator cit = str.begin(); cit != str.end();	++cit)
		std::cout << static_cast<char>(std::toupper(*cit));
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNREADABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
			print_str_upper(argv[i]);
	std::cout << std::endl;
	return (0);
}
