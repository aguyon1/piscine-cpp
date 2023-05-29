/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:48:59 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 10:59:24 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){}

Intern::Intern(const Intern& other){*this = other;};

Intern::~Intern(){};

Intern& Intern::operator=(const Intern& other){(void)other; return (*this);}

static Form* getForm(const std::string& formName, const std::string& formTarget)
{
	Form* form = NULL;

	const Form* forms[NB_FORMS] =
		{new ShrubberyCreationForm(formTarget), new RobotomyRequestForm(formTarget), new PresidentialPardonForm(formTarget)};
	for (int i = 0; i < NB_FORMS && !form; i++)
		if (forms[i]->getName() == formName)
			form = forms[i]->clone();
	for (int i = 0; i < NB_FORMS; i++)
		delete forms[i];
	return (form);
}

Form* Intern::makeForm(std::string formName, std::string formTarget)
{
	Form* form = getForm(formName, formTarget);

	if (form != NULL)
		std::cout << "Intern creates " << form->getName() << std::endl;
	else
		std::cout << formName << " does not exist" << std::endl;
	return (form);
}