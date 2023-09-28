



#ifndef __POINT_H__
# define __POINT_H__

#include <iostream>
#include <cmath>
#include "Fixed.hpp"


class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point( void );
		Point(float const num1, float const num2);
		Point( Point const & src );
		Point & operator=(Point const & rhs);
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif