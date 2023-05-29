/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:57:13 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/24 10:18:49 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cassert>
#include <iostream>

int main(void)
{
	Data data(42, "salut", 42.42, 0.42f), * dataPtrBefore, * dataPtrAfter;
	uintptr_t rawData;



	dataPtrBefore = &data;
	std::cout << "dataPtrBefore : " << dataPtrBefore << std::endl << std::endl;

	rawData = Serializer::serialize(dataPtrBefore);
	std::cout << "rawData (base 10) : " << rawData << std::endl;
	std::cout << "rawData : (base 16) : " << std::hex << rawData << std::endl << std::endl;

	dataPtrAfter = Serializer::deserialize(rawData);
	std::cout << "dataPtrAfter : "<< dataPtrAfter << std::endl;

	assert(dataPtrBefore == dataPtrAfter);
}