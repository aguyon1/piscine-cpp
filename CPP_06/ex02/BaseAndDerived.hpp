/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseAndDerived.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:33:16 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/24 11:21:20 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_AND_DERIVED_HPP
#define BASE_AND_DERIVED_HPP

#include <iostream>
#include "Random.hpp"

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif