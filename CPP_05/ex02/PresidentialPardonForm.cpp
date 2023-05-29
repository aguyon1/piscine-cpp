/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:20:16 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 10:28:03 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("presidential pardon", 25, 5, "")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("presidential pardon", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other)
{}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	Form::operator=(other);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecutePredicate(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}

Form* PresidentialPardonForm::clone() const
{
	return (new PresidentialPardonForm(getTarget()));
}