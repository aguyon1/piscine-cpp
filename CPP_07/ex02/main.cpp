/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:02:43 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/22 23:15:07 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> array(3);

	array[0] = 1;
	array[1] = 2;
	array[2] = 42;

	const Array<int> array2(array);

	try
	{
		array[3] = 5;
	}
	catch(...)
	{
		std::cout << "catch" << std::endl;
	}
	std::cout << array2[2] << std::endl;

	return (0);
}
