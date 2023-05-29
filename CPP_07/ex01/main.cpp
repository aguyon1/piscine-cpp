/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:07:11 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/22 18:30:24 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	add1(int& n)
{
	n++;
}

int	main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 9};
	const size_t sizeArray = 8;

	iter(array, sizeArray, add1);
	iter(array, sizeArray, static_cast<void (*)(const int&)>(print));

	return (0);
}
