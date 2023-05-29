/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:40:11 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 12:37:32 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"

Fire::Fire() : AMateria("fire"){}

Fire::Fire(const Fire& other) : AMateria(other){}

Fire::~Fire(){}

Fire& Fire::operator=(const Fire& other)
{
	_type = other._type;
	return (*this);
}

AMateria* Fire::clone() const
{
	return(new Fire(*this));
}

void Fire::use(ICharacter& target)
{
	std::cout << "* throw a ball of fire at " << target.getName() << " *" << std::endl;
}