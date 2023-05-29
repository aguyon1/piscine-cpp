/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:33 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/16 11:12:08 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other._type)
{
	std::cout << "WrongCat constructed from another" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	_type = other._type;
	std::cout << "WrongCat copied" << std::endl;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Miaouuu" << std::endl;
}