/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Earth.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:37:22 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 11:37:46 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EARTH_HPP
#define EARTH_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Earth : public AMateria
{
	public:
		Earth();
		Earth(const Earth& ice);
		virtual ~Earth();

		Earth& operator=(const Earth& other);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif