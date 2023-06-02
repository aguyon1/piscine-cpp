/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:49:21 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/13 11:49:38 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main(void)
{
	ScavTrap samuel("Samuel"), sarah("Sarah");
	ScavTrap samuel2 = samuel;
	std::string alien("Alien"), monster("Monster");

	std::cout << std::endl;

	samuel.printInfo();
	for (int i = 0; i < 10; ++i)
		samuel.attack(alien);
	samuel.printInfo();
	samuel.beRepaired(5U);

	std::cout << std::endl;

	sarah.printInfo();
	sarah.takeDamage(3U);
	sarah.printInfo();
	sarah.takeDamage(20U);
	sarah.printInfo();
	sarah.attack(monster);

	sarah.guardGate();
	return (0);
}

