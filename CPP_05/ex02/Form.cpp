/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:28:30 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 11:00:35 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: _name(""), _formIsSigned(false), _minGradeSign(0), _minGradeExecute(0), _target("")
{}

Form::Form(const std::string& name, int minGradeSign, int minGradeExecute, const std::string& target)
	: _name(name), _formIsSigned(false), _minGradeSign(minGradeSign), _minGradeExecute(minGradeExecute), _target(target)
{}

Form::Form(const Form& other)
{
	*this = other;
}

Form::~Form(void){}

Form& Form::operator=(const Form& other)
{
	_formIsSigned = other._formIsSigned;
	_minGradeSign = other._minGradeSign;
	_minGradeExecute = other._minGradeExecute;
	return (*this);
}

const std::string& Form::getName(void) const
{
	return (_name);
}

bool Form::isSigned(void) const
{
	return (_formIsSigned);
}

int Form::getMinGradeSign(void) const
{
	return (_minGradeSign);
}

int Form::getMinGradeExecute(void) const
{
	return (_minGradeExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _minGradeSign)
		throw GradeTooLowException();
	_formIsSigned = true;
}

const std::string& Form::getTarget(void) const
{
	return (_target);
}

void Form::checkExecutePredicate(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw FormIsNotSignedException();
	if (executor.getGrade() > _minGradeExecute)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form \"" << form.getName() << "\", " << (form.isSigned() ? "" : "not") << " signed,"
	   << " the minimum grade to sign it : " << form.getMinGradeSign()
	   << ", the minimum grade to execute it : " << form.getMinGradeExecute()
	   << ", target : " << form.getTarget();
	return (os);
}
