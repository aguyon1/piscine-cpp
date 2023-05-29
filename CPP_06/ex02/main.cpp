/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:46:52 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/24 11:58:00 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseAndDerived.hpp"

int main(void)
{
	Base* pbase;
	for (int i = 1; i <= 42; i++)
	{
		std::cout << "[" << i << "]" << std::endl;
		pbase = generate();
		identify(pbase);
		Base& rbase = *pbase;
		identify(rbase);
		std::cout << std::endl;
	}

	return (0);
}