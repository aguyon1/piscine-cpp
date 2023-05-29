/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:23:57 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 13:00:49 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Earth.hpp"
#include "Air.hpp"

static void useCharacterInventory(ICharacter& character, ICharacter& ennemy)
{
	for (int i = 0; i < 4; ++i)
		character.use(i, ennemy);
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Earth());
	//celui ci ne va pas s'apprendre
	AMateria* impossible_to_learn_materia = new Air();
	src->learnMateria(impossible_to_learn_materia);

	ICharacter* me = new Character("me");
	ICharacter* ennemy = new Character("ennemy");

	AMateria* materia_idx_0 = src->createMateria("ice");
	me->equip(materia_idx_0);
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("fire"));
	me->equip(src->createMateria("earth"));
	//celui ci ne va pas s'equiper
	AMateria* impossible_to_equip_materia = src->createMateria("earth");
	me->equip(impossible_to_equip_materia);

	std::cout << std::endl;
	useCharacterInventory(*me, *ennemy);

	me->unequip(0);
	me->equip(src->createMateria("earth"));

	std::cout << std::endl;
	useCharacterInventory(*me, *ennemy);

	delete impossible_to_learn_materia;
	delete impossible_to_equip_materia;
	delete materia_idx_0;
	delete src;
	delete me;
	delete ennemy;

	return 0;
}