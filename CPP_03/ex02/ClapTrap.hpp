/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:27:20 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/13 14:56:16 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printInfo() const;
	protected:
		ClapTrap(const std::string _name, int hitPoints, int energyPoints, int attackDamage);
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	private:
		ClapTrap();

		void printAction(std::string action) const;
};

std::string unsigned_to_string(unsigned int u);

#endif
