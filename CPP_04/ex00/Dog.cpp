/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:40:14 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/16 10:46:38 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other._type)
{
	std::cout << "Dog constructed from another" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	_type = other._type;
	std::cout << "Dog copied" << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Wouuuf" << std::endl;
}