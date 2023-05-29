/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:36:53 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 10:39:55 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string& Contact::getFirstName(void) const
{
	return (this->_firstName);
}

const std::string& Contact::getLastName(void) const
{
	return (this->_lastName);
}

const std::string& Contact::getNickname(void) const
{
	return (this->_nickname);
}

void Contact::print(std::ostream &os) const
{
	os << _firstName << std::endl
	   << _lastName << std::endl
	   << _nickname << std::endl
	   << _phoneNumber << std::endl
	   << _darkestSecret << std::endl;
	return;
}

void Contact::read(std::istream &is)
{
	std::cout << "Enter first name : ";
	std::getline(is, _firstName);
	std::cout << "Enter last name : ";
	std::getline(is, _lastName);
	std::cout << "Enter nickname : ";
	std::getline(is, _nickname);
	std::cout << "Enter phone number : ";
	std::getline(is, _phoneNumber);
	std::cout << "Enter darkest secret : ";
	std::getline(is, _darkestSecret);
	return;
}

bool Contact::isOneFieldEmpty(void) const
{
	return (_firstName.empty() ||
			_lastName.empty() ||
			_nickname.empty() ||
			_phoneNumber.empty() ||
			_darkestSecret.empty());
}

std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
	contact.print(os);
	return (os);
}

std::istream& operator>>(std::istream& is, Contact& contact)
{
	contact.read(is);
	return (is);
}

