/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:51:00 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 10:52:27 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& ice);
		virtual ~Ice();

		Ice& operator=(const Ice& other);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif