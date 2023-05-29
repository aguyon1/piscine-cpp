/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:21:25 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 11:41:46 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	//datas
	private:
		const std::string _name;
		bool _formIsSigned;
		int _minGradeSign;
		int _minGradeExecute;

	//functions
	public:
		Form(const std::string& name, int minGradeSign, int minGradeExecute);
		Form(const Form& other);
		~Form(void);

		Form& operator=(const Form& other);

		const std::string& getName(void) const;
		bool isSigned(void) const;
		int getMinGradeSign(void) const;
		int getMinGradeExecute(void) const;
		void beSigned(const Bureaucrat& bureaucrat);
	private:
		Form(void);
		
	//exception class
	public:
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
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif