/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:04:43 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/21 22:53:43 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
		Point& operator=(const Point& other);
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point& other);
		~Point(void);

		const Fixed& getX(void) const;
		const Fixed& getY(void) const;

};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif

