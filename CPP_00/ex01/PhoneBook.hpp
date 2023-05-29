/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:04:53 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/17 13:12:17 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

// ************************************************************************** //
//                               PhoneBook Class                              //
// ************************************************************************** //

class PhoneBook {

private :
	Contact _contacts[8];
	int _nbContacts;
	void displayContacts(void) const;

public :
	PhoneBook();
	void add(void);
	void search(void) const;
};

#endif /* PHONE_BOOK_HPP ******************************************************/
