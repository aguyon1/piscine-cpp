/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:09:54 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/18 14:12:28 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombies = zombieHorde(NB_ZOMBIES, "Antonin");

	for (int i = 0; i < NB_ZOMBIES; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}
