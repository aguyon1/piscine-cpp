/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:09:09 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/21 23:30:02 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Point::Point(float x, float y) : _x(x), _y(y)
{
	std::cout << "Floats constructor called" << std::endl;
	return;
}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY())
{
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Point::~Point(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

const Fixed&	Point::getX(void) const
{
	return(_x);
}

const Fixed&	Point::getY(void) const
{
	return(_y);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Point AB(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	const Point BC(c.getX().toFloat() - b.getX().toFloat(), c.getY().toFloat() - b.getY().toFloat());
	const Point CA(a.getX().toFloat() - c.getX().toFloat(), a.getY().toFloat() - c.getY().toFloat());
	const Point AP(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());
	const Point BP(point.getX().toFloat() - b.getX().toFloat(), point.getY().toFloat() - b.getY().toFloat());
	const Point CP(point.getX().toFloat() - c.getX().toFloat(), point.getY().toFloat() - c.getY().toFloat());

	const float det1 = (AB.getX() * AP.getX() + AB.getY() * AP.getY()).toFloat();
	const float det2 = (BC.getX() * BP.getX() + BC.getY() * BP.getY()).toFloat();
	const float det3 = (CA.getX() * CP.getX() + CA.getY() * CP.getY()).toFloat();

	return ((det1 > 0 && det2 > 0 && det3 > 0)
			|| (det1 < 0 && det2 < 0 && det3 < 0));
}
