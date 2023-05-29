/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Air.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:38:24 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 11:38:42 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AIR_HPP
#define AIR_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Air : public AMateria
{
	public:
		Air();
		Air(const Air& ice);
		virtual ~Air();

		Air& operator=(const Air& other);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif