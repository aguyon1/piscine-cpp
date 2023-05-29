/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseAndDerived.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:33:11 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/24 11:56:14 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseAndDerived.hpp"

Base::~Base(){}

static Random randomm;

Base * generate(void)
{
	Base * ptr;
	int random_int = randomm.integer(1, 3);

	switch(random_int)
	{
		case 1 :
			ptr = new A();
			break;
		case 2 :
			ptr = new B();
			break;
		case 3 :
			ptr = new C();
			break;
	}
	return (ptr);
}

static void printPointerSentence(char pointerName, char objectName)
{
	std::cout << pointerName << " point to an object of type " << objectName << std::endl;
}

void identify(Base * p)
{
	if (dynamic_cast<A*>(p) != NULL)
		printPointerSentence('p', 'A');
	else if (dynamic_cast<B*>(p) != NULL)
		printPointerSentence('p', 'B');
	else if (dynamic_cast<C*>(p) != NULL)
		printPointerSentence('p', 'C');
}

static void printReferenceSentence(char referenceName, char objectName)
{
	std::cout << referenceName << " reference an object of type " << objectName << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		printReferenceSentence('p', 'A');
	}
	catch(const std::bad_cast& e){}

	try
	{
		dynamic_cast<B&>(p);
		printReferenceSentence('p', 'B');
	}
	catch(const std::bad_cast& e){}

	try
	{
		dynamic_cast<C&>(p);
		printReferenceSentence('p', 'C');
	}
	catch(const std::bad_cast& e){}
}