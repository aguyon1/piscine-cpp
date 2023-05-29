/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:25:13 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 11:36:04 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat antonin("antonin", 42);
	Form form1("form1", 50, 50);
	Form form2("form2", 30, 30);

	std::cout << "//" << antonin.getName() << " try to sign " << form1.getName() << std::endl;
	antonin.signForm(form1);
	std::cout << std::endl;

	std::cout << "//" << antonin.getName() << " try to sign " << form2.getName() << std::endl;
	antonin.signForm(form2);
	std::cout << std::endl;

	std::cout << "//" << antonin.getName() << " try to sign " << form2.getName() << std::endl;
	antonin.promotion(20);
	antonin.signForm(form2);
	std::cout << std::endl;

	return (0);
}