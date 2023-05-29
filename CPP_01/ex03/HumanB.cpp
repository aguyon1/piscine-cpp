/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:56:28 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/20 09:51:17 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string human_name) : _human_name(human_name), _pweapon(NULL)
{
	return;
}

void	HumanB::setWeapon(Weapon &pweapon)
{
	_pweapon = &pweapon;
	return;
}

void HumanB::attack(void) const
{
	std::string strWeapon = ((_pweapon == NULL) ? "hands" : _pweapon->getType());

	std::cout << _human_name << " attacks with their " << strWeapon << std::endl;
	return;
}
