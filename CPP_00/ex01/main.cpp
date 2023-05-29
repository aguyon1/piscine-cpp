/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:19:07 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/17 12:29:03 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string command;
	PhoneBook phoneBook;

	while (true)
	{
		std::cout << "Enter command : ";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			phoneBook.add();
		else if (command.compare("SEARCH") == 0)
			phoneBook.search();
		else if (command.compare("EXIT") == 0)
			std::exit(0);
		else
			std::cout << "Command not found" << std::endl;
	}
	return (0);
}
