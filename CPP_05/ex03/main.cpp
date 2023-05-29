/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:28:56 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/19 10:54:52 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Form *rrf, *ppf, *scf, *nonexistent;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	ppf = someRandomIntern.makeForm("presidential pardon", "Antonin");
	nonexistent = someRandomIntern.makeForm("nonexistent form", "nothing");
	(void)nonexistent;
	
	std::cout << std::endl;
	std::cout << *rrf << std::endl << *scf << std::endl << *ppf << std::endl;

	delete rrf;
	delete scf;
	delete ppf;
}