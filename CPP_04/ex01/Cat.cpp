/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:36:16 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/17 09:04:00 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other._type)
{
	*_brain = *(other._brain);
	std::cout << "Cat constructed from another" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructed" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	_type = other._type;
	_brain = new Brain(*(other._brain));
	std::cout << "Cat copied" << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Miaouuu" << std::endl;
}