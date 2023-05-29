/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:03:17 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/16 12:32:04 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		virtual ~AAnimal(void);

		AAnimal& operator=(const AAnimal& other);

		virtual void makeSound(void) const = 0;
		const std::string& getType(void) const;
	protected:
		std::string _type;
};

#endif