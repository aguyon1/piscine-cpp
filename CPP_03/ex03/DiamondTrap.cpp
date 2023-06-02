/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:38:06 by aguyon            #+#    #+#             */
/*   Updated: 2023/06/02 13:54:38 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : 
{

}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{

}

DiamondTrap::~DiamondTrap()
{
	printAction("has been destroyed.");
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other);

void DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name : " << this->_name << ", ClapTrap name : " << ClapTrap::_name << std::endl;
}

void DiamondTrap::printAction(std::string action) const
{
	std::cout << "DiamondTrap " << _name << " " << action << std::endl;
}