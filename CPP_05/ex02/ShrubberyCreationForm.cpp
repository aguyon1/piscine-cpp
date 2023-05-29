/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:02 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 10:29:04 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("shrubbery creation", 145, 137, "")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("shrubbery creation", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	Form::operator=(other);
	return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecutePredicate(executor);
	const std::string filename(getTarget() + "_shrubbery");
	std::ofstream file(filename.c_str(), std::ios::out | std::ios::trunc);

	if (file.is_open())
	{
		file << ShrubberyCreationForm::_tree;
		file.close();
	}
	std::cout << executor.getName() << " execute " << this->getName() << " to " << getTarget() << std::endl;
}

Form* ShrubberyCreationForm::clone() const
{
	return (new ShrubberyCreationForm(getTarget()));
}

std::string ShrubberyCreationForm::_tree =
"              v .   ._, |_  .,                       v .   ._, |_  .,\n           `-._\\/  .  \\ /    |/_                  `-._\\/  .  \\ /    |/_\n               \\\\  _\\, y | \\//                        \\\\  _\\, y | \\//\n         _\\_.___\\\\, \\\\/ -.\\||                   _\\_.___\\\\, \\\\/ -.\\||\n           `7-,--.`._||  / / ,                    `7-,--.`._||  / / ,\n           /'     `-. `./ / |/_.'                 /'     `-. `./ / |/_.'\n                     |    |//                              |    |//\n                     |_    /                               |_    /\n                     |-   |                                |-   |\n                     |   =|                                |   =|\n                     |    |                                |    |\n--------------------/ ,  . \\--------._--------------------/ ,  . \\--------._\n";