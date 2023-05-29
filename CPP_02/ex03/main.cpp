/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:26:36 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/21 23:33:12 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void)
{
	Point A(1.0f, 1.0f);
	Point B(5.0f, 1.0f);
	Point C(1.0f, 4.0f);
	Point P(3.0f, 4.0f);

	std::cout << (bsp(A, B, C, P) ? "TRUE" : "FALSE") << std::endl;
}
