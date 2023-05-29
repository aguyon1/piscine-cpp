/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:00:09 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 11:33:34 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	//Pas d'erreur
	std::cout << "//Try to create new bureaucrat, grade 42 :" << std::endl;
	try
	{
		Bureaucrat antonin("Antonin", 42);
		std::cout << antonin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "//Try to create new bureaucrat, grade 160 :" << std::endl;
	//Grade trop faible
	try
	{
		Bureaucrat antonin("Antonin", 160);
		std::cout << antonin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "//Try to create new bureaucrat, grade 0 :" << std::endl;
	//Grade trop eleve
	try
	{
		Bureaucrat antonin("Antonin", 0);
		std::cout << antonin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "//Try to get promoted" << std::endl;
	try
	{
		Bureaucrat antonin("Antonin", 42);
		antonin.promotion(10);
		std::cout << antonin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "//Try to get demoted" << std::endl;
	try
	{
		Bureaucrat antonin("Antonin", 42);
		antonin.demotion(10);
		std::cout << antonin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "//Try to incremente bureaucrat grade 1:" << std::endl;
	//Imposible de promouvoir le bureaucrate
	try
	{
		Bureaucrat antonin("Antonin", 1);
		antonin++;
		std::cout << antonin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "//Try to decremente bureaucrat grade 150:" << std::endl;
	//impossible de retrogader le bureaucrate
	try
	{
		Bureaucrat antonin("Antonin", 150);
		antonin--;
		std::cout << antonin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	return (0);
}