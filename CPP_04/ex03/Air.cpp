/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Air.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:38:49 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 11:40:01 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Air.hpp"

Air::Air() : AMateria("air"){}

Air::Air(const Air& other) : AMateria(other){}

Air::~Air(){}

Air& Air::operator=(const Air& other)
{
	_type = other._type;
	return (*this);
}

AMateria* Air::clone() const
{
	return(new Air(*this));
}

void Air::use(ICharacter& target)
{
	std::cout << "* throws a tornado on " << target.getName() << " *" << std::endl;
}