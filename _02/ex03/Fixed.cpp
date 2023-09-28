/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:19:30 by clballes          #+#    #+#             */
/*   Updated: 2023/09/26 13:19:31 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int	Fixed::_fractBits = 8;

//default
Fixed::Fixed(void) : _value( 0 )
{
	// std::cout << "Default Constructor called" << std::endl;
	return ;
}

//copy constructor
Fixed::Fixed(const int num) : _value( num )
{
	// std::cout << "Int Constructor called" << std::endl;
	this->_value = (num << _fractBits);
	return ;
}

Fixed::Fixed(const float num) : _value( num )
{
	// std::cout << "Fixed-Float Constructor called" << std::endl;
	this->_value = int(roundf(num * (1 << this->_fractBits)));
	return;
}

Fixed::Fixed( Fixed const & src )
{
	// std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}


//Operators calling
bool Fixed::operator==(Fixed const & rhs) const
{
	return this->_value > rhs._value;
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return this->_value != rhs._value;
}

bool Fixed::operator>(Fixed const & rhs) const
{
	return this->_value > rhs._value;
}
bool Fixed::operator>=(Fixed const & rhs) const
{
	return this->_value >= rhs._value;
}

bool Fixed::operator<(Fixed const & rhs) const
{
	return this->_value < rhs._value;
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return this->_value <= rhs._value;
}


// The 4 arithmetic operators: +, -, *, and
Fixed Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->_value + rhs.getRawBits());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->_value - rhs.getRawBits());
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed tmp;

	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed tmp;

	if (!rhs._value)
		return Fixed(0);
	return Fixed(this->toFloat() / rhs.toFloat());
}

// increment and post inrement
Fixed  Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed  Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
  	operator++(); // prefix-increment this instance
  	return tmp;   // return value before increment
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
  	operator--(); // prefix-increment this instance
  	return tmp;   // return value before increment
}



//Destrcuor called
Fixed::~Fixed()
{
	return ;
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_fractBits);
}

float Fixed::toFloat( void ) const
{
	return (this->_value / pow(2, this->_fractBits));
}

float Fixed::getRawBits( void ) const
{
	return this->_value; 
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
	return ;
}



//member public function operator
// Fixed& Fixed::min(Fixed& a, Fixed& b)
// {
// 	if (a._value <= b._value)
// 		return a;
// 	else
// 		return b;
// }

const Fixed& Fixed::min(const Fixed &  a, const Fixed & b ) //es cconst no podem modificar el value
{
	if (a._value <= b._value)
		return a;
	else
		return b;
}

// Fixed& Fixed::max(Fixed& a, Fixed& b)
// {
// 	if (a._value >= b._value)
// 		return a;
// 	else
// 		return b;
// }

const Fixed& Fixed::max(const Fixed &  a, const Fixed & b )
{
	if (a._value >= b._value)
		return a;
	else
	{
		return b;
	}
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}

std::ostream &	max( std::ostream & o, Fixed const & lhs, Fixed const & rhs )
{
	o << Fixed::max(lhs, rhs);
	return	(o);
}

std::ostream &	min( std::ostream & o, Fixed const & lhs, Fixed const & rhs )
{
	o << Fixed::min(lhs, rhs);
	return	(o);
}