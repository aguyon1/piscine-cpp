/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:36:54 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/18 14:43:55 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "L'adresse de la string : " << &str << std::endl;
	std::cout << "L'adresse stocke dans stringPTR : " << stringPTR << std::endl;
	std::cout << "L'adresse stocke dans stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "La valeur de la string : " << str << std::endl;
	std::cout << "La valeur pointe par stringPTR : " << *stringPTR << std::endl;
	std::cout << "La valeur pointe par stringREF : " << stringREF << std::endl;

	return (0);
}
