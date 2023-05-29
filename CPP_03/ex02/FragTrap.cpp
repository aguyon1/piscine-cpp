/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:18:45 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/13 14:58:11 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name)
	: ClapTrap(name, 100, 50, 20)
{
	printAction("has been constructed.");
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
	printAction("has been constructed from another.");
}

FragTrap::~FragTrap()
{
	printAction("has been destroyed.");
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::string oldName = _name;
	*this = other;
	std::cout << "A FragTrap " << oldName << " is now similar to " << other._name << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	printAction("made a high five.");
}

void FragTrap::printAction(std::string action) const
{
	std::cout << "FragTrap " << _name << " " << action << std::endl;
}
