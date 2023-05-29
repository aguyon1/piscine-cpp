/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:53:19 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/19 19:10:05 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		std::string _human_name;
		Weapon* _pweapon;
	public:
		HumanB(std::string human_name);
		void setWeapon(Weapon &weapon);
		void attack(void) const;
};

#endif
