/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:32:32 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 12:41:22 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}


MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
	deleteTemplates();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	deleteTemplates();
	for (int i = 0; i < 4; i++)
		_templates[i] = other._templates[i];
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = m;
			return ;
		}
	}
	std::cout << "No space available for new materia template" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 3; i >= 0; i--)
		if (_templates[i] != NULL && type == _templates[i]->getType())
			return (_templates[i]->clone());
	std::cout << "Materia doesn't exists" << std::endl;
	return (0);
}

void MateriaSource::deleteTemplates(void)
{
	for (int i = 0; i < 4; i++)
		if (_templates[i] != NULL)
			delete _templates[i];
}