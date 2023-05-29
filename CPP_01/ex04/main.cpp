/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:52:38 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/18 21:56:59 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		std::ifstream infile(argv[1]);
		if (infile.is_open())
		{

		}
	}
	return (0);
}
