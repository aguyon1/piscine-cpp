/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:04:42 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/17 13:20:53 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
PhoneBook::PhoneBook() : _nbContacts(0)
{
	for (int i = 0; i < 8; i++)
		_contacts[i] = Contact();
	return;
}

void PhoneBook::add(void)
{
	Contact contact;

	do
	{
		std::cin >> contact;
		if (contact.isOneFieldEmpty())
			std::cout << "One field is empty !" << std::endl;
	} while (contact.isOneFieldEmpty());
	_contacts[_nbContacts % 8] = contact;
	_nbContacts++;
	return;
}

std::string formatString(const std::string& str)
{
	const size_t len = str.length();
	std::string cpy(str);

	if (len > 10)
		cpy.replace(9, len - 9, ".");
	return (cpy);
}

void PhoneBook::displayContacts(void) const
{
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickName;

	std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First name" << "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < (_nbContacts < 8 ? _nbContacts : 8); i++)
	{
		contact = _contacts[i];
		firstName = contact.getFirstName();
		lastName = contact.getLastName();
		nickName = contact.getNickname();

		std::cout << std::right << std::setw(10) << i << "|"
				  << std::right << std::setw(10) << formatString(firstName) << "|"
				  << std::right << std::setw(10) << formatString(lastName) << "|"
				  << std::right << std::setw(10) << formatString(nickName) << "|"
				  << std::endl;
	}
	return;
}

void PhoneBook::search(void) const
{
	int index;

	displayContacts();
	do
	{
		std::cout << "Enter the index to display : " << std::endl;
		std::cin >> index;
	} while (index < 0 || index > 7 || (_nbContacts < index));
	std::cout << _contacts[index];
	return;
}


