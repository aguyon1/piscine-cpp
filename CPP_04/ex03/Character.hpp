/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:22:04 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 10:53:38 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstring>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class ICharacter;
class AMateria;

class Character : public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character& other);
		virtual ~Character(void);

		Character& operator=(const Character& other);
		virtual std::string  const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		void deleteInventory(void);

		std::string _name;
		AMateria* _inventory[4];
};


#endif