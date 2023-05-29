/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:13:50 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 09:58:34 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "utils.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::cout << "~~Test avec la mutant stack~~" << std::endl << std::endl;
	MutantStack<int> mstack(13);
	std::cout << "//Generation des elements de la stack mutante" << std::endl;
	std::generate(mstack.begin(), mstack.end(), FibonacciFunctor());
	std::cout << "Affichage en partant du debut" << std::endl;
	std::copy(mstack.cbegin(), mstack.cend(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
	std::cout << "Affichage en partant de la fin" << std::endl;
	std::copy(mstack.crbegin(), mstack.crend(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
	std::cout << "Partionnement de la mutant stack (pair a gauche, impair a droite)" << std::endl;
	std::stable_partition(mstack.begin(), mstack.end(), IsEvenFunctor());
	std::copy(mstack.cbegin(), mstack.cend(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
	std::cout << "Tri de la mutant stack mais en utilisant les reverse iterators" << std::endl;
	std::sort(mstack.rbegin(), mstack.rend());
	std::copy(mstack.cbegin(), mstack.cend(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "~~Test avec un vector~~" << std::endl << std::endl;
	std::vector<int> vec(13);
	std::cout << "//Generation des elements du vector" << std::endl;
	std::generate(vec.begin(), vec.end(), FibonacciFunctor());
	std::cout << "Affichage en partant du debut" << std::endl;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
	std::cout << "Affichage en partant de la fin" << std::endl;
	std::copy(vec.rbegin(), vec.rend(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
	std::cout << "Partionnement du vector (pair a gauche, impair a droite)" << std::endl;
	std::stable_partition(vec.begin(), vec.end(), IsEvenFunctor());
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
	std::cout << "Tri du vector mais en utilisant les reverse iterators" << std::endl;
	std::sort(vec.rbegin(), vec.rend());
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
}