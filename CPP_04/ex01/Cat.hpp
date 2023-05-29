/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:13:53 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/16 11:59:57 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& other);
		virtual ~Cat(void);

		Cat& operator=(const Cat& other);
		virtual void makeSound(void) const;
	private:
		Brain* _brain;

};

#endif