/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:32:49 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 10:39:35 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Contact
{

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	const std::string& getFirstName(void) const;
	const std::string& getLastName(void) const;
	const std::string& getNickname(void) const;

	bool isOneFieldEmpty(void) const;
	void print(std::ostream &os) const;
	void read(std::istream &is);
};

std::ostream& operator<<(std::ostream& os, const Contact& contact);
std::istream& operator>>(std::istream& is, Contact& contact);

#endif /* CONTACT_HPP *********************************************************/
