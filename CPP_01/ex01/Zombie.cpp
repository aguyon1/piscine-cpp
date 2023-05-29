/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:03:35 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/19 18:57:43 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie is born." << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cerr << "A zombie " << _name << " died." << std::endl;
	return;
}

void	Zombie::announce(void) const
{
	std::cout << "Hello, my name is : " << _name << "." << std::endl;
	return;
}

Zombie&	Zombie::setName(const std::string& name)
{
	_name = name;
	return (*this);
}
