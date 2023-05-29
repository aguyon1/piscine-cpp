/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:34:25 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/12 18:15:22 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Nameless"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "An unnamed ClapTrap has been constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	printAction("has been constructed.");
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	printAction("has been constructed from another.");
}

ClapTrap::~ClapTrap()
{
	printAction("has been destroyed.");
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::string oldName = _name;

	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "A ClapTrap " << oldName << " is now similar to " << other._name << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		printAction("can't take damage.");
	}
	else
	{
		printAction("take " + unsigned_to_string(amount) + " point of damage!");
		int newHitPoints = _hitPoints - static_cast<int>(amount);
		_hitPoints = newHitPoints < 0 ? 0 : newHitPoints;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
		if (_hitPoints == 0 || _energyPoints == 0)
	{
		printAction("can't be repaired.");
	}
	else
	{
		printAction("regains " + unsigned_to_string(amount) + " hit points!");
		_energyPoints--;
	}
}

void ClapTrap::printAction(std::string action) const
{
	std::cout << "ClapTrap " << _name << " " << action << std::endl;
}

void ClapTrap::printInfo() const
{
	printAction("has " +
	unsigned_to_string(_hitPoints) + " hit points, " +
	unsigned_to_string(_energyPoints) + " energy points and " +
	unsigned_to_string(_attackDamage) + " attack damage.");
}

static void unsigned_to_string_rec(std::string& str, unsigned int u)
{
	if (u == 0U)
		return;
	else
		unsigned_to_string_rec(str, u / 10U), str.push_back(u % 10U + '0');
}

std::string unsigned_to_string(unsigned int u)
{
	std::string str;

	if (u == 0U)
		str.push_back('0');
	else
		unsigned_to_string_rec(str, u);
	return (str);
}
