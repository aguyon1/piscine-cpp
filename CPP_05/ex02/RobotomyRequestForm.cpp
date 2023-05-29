/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:21:19 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 10:26:17 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("robotomy request", 72, 45, "")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("robotomy request", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other)
{}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	Form::operator=(other);
	return (*this);
}

static int generateNumber(int n, int m)
{
	srand((unsigned) time(NULL));

	return(rand() % (m + 1) + n);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecutePredicate(executor);
	std::cout << "*Drill noises*" << std::endl;
	int random = generateNumber(0, 1);
	if (random)
		std::cout << getTarget() << " has been robotomised" << std::endl;
	else
		std::cout << "Operation failed" << std::endl;
}

Form* RobotomyRequestForm::clone() const
{
	return (new RobotomyRequestForm(getTarget()));
}