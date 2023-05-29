/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Earth.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:40:51 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 12:37:38 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Earth.hpp"

Earth::Earth() : AMateria("earth"){}

Earth::Earth(const Earth& other) : AMateria(other){}

Earth::~Earth(){}

Earth& Earth::operator=(const Earth& other)
{
	_type = other._type;
	return (*this);
}

AMateria* Earth::clone() const
{
	return(new Earth(*this));
}

void Earth::use(ICharacter& target)
{
	std::cout << "* creates an earthquake below " << target.getName() << " *" << std::endl;
}