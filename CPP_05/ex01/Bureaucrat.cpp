/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:39:07 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 11:44:07 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	: _name(""), _grade(42)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	_grade = other._grade;
	return (*this);
}

const std::string& Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::printPromotion() const
{
	std::cout << _name << " has been promoted to grade : " << _grade << std::endl;
}

void Bureaucrat::printDemotion() const
{
	std::cout << _name << " has been demoted to grade : " << _grade << std::endl;
}

void Bureaucrat::promotion(int nbGrade)
{
	if (_grade - nbGrade < 1)
		throw GradeTooHighException();
	_grade -= nbGrade;
	printPromotion();
}

void Bureaucrat::demotion(int nbGrade)
{
	if (_grade + nbGrade > 150)
		throw GradeTooHighException();
	_grade += nbGrade;
	printDemotion();
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat tmp(_name, _grade - 1);
	_grade--;
	printPromotion();
	return (tmp);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat tmp(_name, _grade + 1);
	_grade++;
	printDemotion();
	return (tmp);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}