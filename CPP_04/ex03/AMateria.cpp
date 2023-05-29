/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:27 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/17 10:07:59 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("None"){}

AMateria::AMateria(std::string const & type) : _type(type){}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}

AMateria::~AMateria(){}

AMateria& AMateria::operator=(const AMateria& other)
{
	_type = other._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* Use of " << _type << " to " << target.getName() << " *" << std::endl;
}