/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:26:14 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/18 19:47:07 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

struct s_comment
{
	const std::string name;
	void (Harl::*fun)(void) const;
};
void	Harl::debug(void) const
{
	std::cout << "[DEBUG]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
			  << "I really do !"
			  << std::endl;
	return;
}

void	Harl::info(void) const
{
	std::cout << "[INFO]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger ! "
			  << "If you did, I wouldn’t be asking for more !"
			  << std::endl;
	return;
}

void	Harl::warning(void) const
{
	std::cout << "[WARNING]" << std::endl
			  << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years whereas you started working here since last month."
			  << std::endl;
	return;
}

void	Harl::error(void) const
{
	std::cout << "[ERROR]" << std::endl
			  << "This is unacceptable ! "
			  << "I want to speak to the manager now."
			  << std::endl;
	return;
}

void	Harl::complain(std::string level) const
{
	const struct s_comment comments[4] =
		{{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}};

	for (int i = 0; i < 4; i++)
		if (comments[i].name.compare(level) == 0)
			(this->*(comments[i].fun))();
	return;
}

