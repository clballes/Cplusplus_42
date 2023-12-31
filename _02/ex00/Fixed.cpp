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

const int	Fixed:: _fractBits = 8;

Fixed::Fixed() : _value( 0 )
{
	std::cout << "Default Constructor called" << std::endl;
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
	std::cout << "Operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value; 
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}