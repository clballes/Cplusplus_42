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
#include <bitset>


const int	Fixed::_fractBits = 8;

//default
Fixed::Fixed(void) : _value( 0 )
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

//copy constructor
Fixed::Fixed(const int num) : _value( num )
{
	std::cout << "Int Constructor called" << std::endl;
	this->_value = (num << _fractBits);
	return ;
}

Fixed::Fixed(const float num) : _value( num )
{
	std::cout << "Fixed-Float Constructor called" << std::endl;
	this->_value = int(roundf(num * (1 << this->_fractBits)));
	return;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

//Destrcuor called
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}
