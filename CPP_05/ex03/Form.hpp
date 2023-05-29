/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:21:25 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 10:53:53 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	//data
	private:
		const std::string _name;
		bool _formIsSigned;
		int _minGradeSign;
		int _minGradeExecute;
		std::string _target;

	//functions
	private:
		Form(void);
	protected:
		void checkExecutePredicate(Bureaucrat const & executor) const;
	public:
		Form(const std::string& name, int minGradeSign, int minGradeExecute, const std::string& target);
		Form(const Form& other);
		virtual ~Form(void);

		Form& operator=(const Form& other);
		const std::string& getName(void) const;
		bool isSigned(void) const;
		int getMinGradeSign(void) const;
		int getMinGradeExecute(void) const;
		void beSigned(const Bureaucrat& bureaucrat);
		const std::string& getTarget() const;
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual Form* clone() const = 0;

		//exception class
		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char * what() const throw()
			{
				return ("Grade too high!");
			}
		};

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char * what() const throw()
			{
				return ("Grade too low!");
			}
		};

		class FormIsNotSignedException : public std::exception
		{
		public:
			virtual const char * what() const throw()
			{
				return ("Form is not signed!");
			}
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif