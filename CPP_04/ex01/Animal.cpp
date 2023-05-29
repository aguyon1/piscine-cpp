/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:06:43 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/16 10:52:06 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("No type")
{
	std::cout << "Typeless animal constructed" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal constructed from : " << other._type << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructed" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	_type = other._type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}

const std::string& Animal::getType(void) const
{
	return (_type);
}