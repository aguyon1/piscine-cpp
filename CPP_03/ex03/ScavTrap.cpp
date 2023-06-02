/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:40:57 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/13 14:59:16 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name)
	: ClapTrap(name, 100, 50, 20)
{
	printAction("has been constructed.");
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
	printAction("has been constructed from another.");
}

ScavTrap::~ScavTrap()
{
	printAction("has been destroyed.");
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::string oldName = _name;
	*this = other;
	std::cout << "A ScavTrap " << oldName << " is now similar to " << other._name << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		printAction("can't attack.");
	}
	else
	{
		printAction("attacks " + target + ", causing " + unsigned_to_string(_attackDamage) + " point of damage!");
		_energyPoints--;
	}
}

void ScavTrap::guardGate()
{
	printAction("is in gate keeper mode.");
}

void ScavTrap::printAction(std::string action) const
{
	std::cout << "ScavTrap " << _name << " " << action << std::endl;
}

