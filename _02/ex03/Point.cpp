
// #include "Fixed.hpp"
#include "Point.hpp"

//construcctor called and initialized to 0
Point::Point() : _x(0), _y(0) {}

Point::Point(float const num1, float const num2) : _x(num1), _y(num2) {}

Point::Point( Point const & src )
{
	*this = src;
	return ;
}

Point & Point::operator=(Point const & rhs)
{
	const_cast<Fixed&>(_x) = rhs._x;
	const_cast<Fixed&>(_y) = rhs._y;
	return *this;

}

//destructor called
Point::~Point()
{
	std::cout << "destructor called" << std::endl;
	return;
}