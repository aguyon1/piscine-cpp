/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:06:43 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/16 12:34:45 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("No type")
{
	std::cout << "Typeless Animal constructed" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Animal constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "Animal constructed from : " << other._type << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructed" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	_type = other._type;
	return (*this);
}

void AAnimal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}

const std::string& AAnimal::getType(void) const
{
	return (_type);
}