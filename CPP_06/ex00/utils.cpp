/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:03:04 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/22 11:38:30 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

MyVector<std::string> split(const std::string& input, char sep)
{
	std::stringstream ss(input);
	std::string s;
	MyVector<std::string> res;

	while (std::getline(ss, s, sep))
		res.push_back(s);
	return (res);
}
