/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:35:47 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/17 09:07:52 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ARRAY_SIZE 10

int main(void)
{
	Animal *animalsArray[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE / 2; i++)
	{
		std::cout << "id animal : " << i << std::endl;
		animalsArray[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++)
	{
		std::cout << "id animal : " << i << std::endl;
		animalsArray[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << "id animal : " << i << std::endl;
		delete animalsArray[i];
		std::cout << std::endl;
	}
	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat();

	*cat2 = *cat1;

	delete cat1;
	delete cat2;

	return (0);
}