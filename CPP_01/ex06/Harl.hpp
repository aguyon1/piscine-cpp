/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:24:10 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/18 16:51:43 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Harl_H
#define Harl_H

#include <string>
#include <iostream>

class Harl
{
	private:
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
	public:
		void	complain(std::string level) const;
};

#endif
