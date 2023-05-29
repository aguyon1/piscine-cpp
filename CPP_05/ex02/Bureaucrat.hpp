/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:24:45 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 11:42:55 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	//datas
	private:
		const std::string _name;
		int _grade;

	//functions
	private:
		Bureaucrat(void);
		void printPromotion() const;
		void printDemotion() const;
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);

		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string& getName(void) const;
		int getGrade(void) const;

		void promotion(int nbGrade);
		void demotion(int nbGrade);
		Bureaucrat operator++(int);
		Bureaucrat operator--(int);

		void signForm(Form& form) const;
		void executeForm(Form const & form) const;

	//exception class
	public:
		class GradeTooHighException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Grade too high!");
			}
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Grade too low!");
			}
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif