/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:48:54 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/18 14:42:02 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat random("random", 150);

	//ShrubberyCreation Test
	std::cout << "~~Schrubbery creation test~~" << std::endl << std::endl;

	Bureaucrat gardenKeeper("garden keeper", 140);
	Bureaucrat mayor("mayor", 55);
	ShrubberyCreationForm revegetation("garden");

	std::cout << "//random try to sign shrubbery creation" << std::endl;
	random.signForm(revegetation);
	std::cout << std::endl;

	std::cout << "//random try to execute shrubbery creation" << std::endl;
	random.executeForm(revegetation);
	std::cout << std::endl;

	std::cout << "//garden keeper try to sign shrubbery creation" << std::endl;
	gardenKeeper.signForm(revegetation);
	std::cout << std::endl;

	std::cout << "//mayor try to resign shrubbery creation" << std::endl;
	mayor.signForm(revegetation);
	std::cout << std::endl;

	std::cout << "//mayor try to execute shrubbery creation" << std::endl;
	mayor.executeForm(revegetation);
	std::cout << std::endl;



	//RobotomyRequest Test
	std::cout << "~~Robotomy creation test~~" << std::endl << std::endl;

	Bureaucrat robotDoctor("robot doctor", 42);
	Bureaucrat doctorAssistant("robot doctor's assistant", 67);
	RobotomyRequestForm robotomy("robot");

	std::cout << "//random try to sign robotomy request" << std::endl;
	random.signForm(robotomy);
	std::cout << std::endl;

	std::cout << "//doctor's assistant try to sign robotomy request" << std::endl;
	doctorAssistant.signForm(robotomy);
	std::cout << std::endl;

	std::cout << "//random try to execute robotomy request" << std::endl;
	random.executeForm(robotomy);
	std::cout << std::endl;

	std::cout << "//doctor try to execute robotomy request" << std::endl;
	robotDoctor.executeForm(robotomy);
	std::cout << std::endl;



	//PrisidentialPardon Test
	std::cout << "~~Presidential pardon test~~" << std::endl << std::endl;

	Bureaucrat president("president", 1);
	Bureaucrat primeMinister("prime minister", 10);
	PresidentialPardonForm presidentialPardon("antonin");

	std::cout << "// prime minister try to presidential pardon" << std::endl;
	primeMinister.signForm(presidentialPardon);
	std::cout << std::endl;

	std::cout << "// prime minister try to execute presidential pardon" << std::endl;
	primeMinister.executeForm(presidentialPardon);
	std::cout << std::endl;

	std::cout << "// president try to execut presidential pardon" << std::endl;
	president.executeForm(presidentialPardon);
	std::cout << std::endl;
}