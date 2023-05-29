/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:49:21 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/13 11:21:23 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap carl("Carl"), cameron("Cameron");
	ClapTrap carl2 = carl;
	ClapTrap carl3;
	carl3 = carl2;
	std::string alien("Alien"), monster("Monster");

	std::cout << std::endl;

	carl.printInfo();
	for (int i = 0; i < 10; ++i)
		carl.attack(alien);
	carl.printInfo();
	carl.beRepaired(5U);

	std::cout << std::endl;

	cameron.printInfo();
	cameron.takeDamage(3U);
	cameron.printInfo();
	cameron.takeDamage(20U);
	cameron.printInfo();
	cameron.attack(monster);

	return (0);
}

