/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:05 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/18 13:59:20 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : _name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cerr << "Zombie " << _name << " died." << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << "Hello, my name is : " << _name << std::endl;
}
