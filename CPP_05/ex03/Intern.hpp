/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:45:44 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 10:41:46 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define NB_FORMS 3

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void);

		Intern& operator=(const Intern& other);

		Form* makeForm(std::string formName, std::string formTarget);
};

#endif