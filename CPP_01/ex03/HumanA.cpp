/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:07:47 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/19 19:08:14 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon& weapon)
	: _human_name(human_name), _weapon(weapon)
{
	return;
}

void HumanA::attack(void) const
{
	std::cout <<_human_name << " attacks with their " << _weapon.getType() << std::endl;
}
