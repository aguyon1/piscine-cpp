/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:17:22 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/13 14:20:56 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(const std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();
		FragTrap& operator=(const FragTrap& other);

		void highFivesGuys(void);
	private:
		FragTrap();

		void printAction(std::string action) const;
};

#endif
