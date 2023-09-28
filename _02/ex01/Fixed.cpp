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


const int	Fixed:: _fractBits = 8;

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
	std::cout << "Before binary representation of _rawBits: " << std::bitset<16>(_value) << std::endl;
	
	this->_value = (num << Fixed::_fractBits);
	std::cout << "Binary representation of _rawBits: " << std::bitset<16>(_value) << std::endl;
    
	return ;
}

Fixed::Fixed(const float num) : _value( num )
{
	_value = static_cast<int>(num);
	std::cout << "Fixed-Float Constructor called" << std::endl;
	return ;
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::toInt( void ) const
{
	std::cout << "funciton int member" << std::endl;
	return _value;
}

// t converts the fixed-point value to a floating-point value.
float Fixed::toFloat( void ) const
{
	std::cout << "funcition float member" << std::endl;
	return 4;

}

float Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value; 
}