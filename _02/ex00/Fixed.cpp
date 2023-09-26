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

Fixed::Fixed()
{
	std::cout << "constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "copy constructor called" << std::endl;
	*this = src;
	std::cout << "src es " << &src << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const &src)
{
	std::cout << "opertor  called" << std::endl;
	if (this != &src)
		this->_value = 3;
	return *this;
}
Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	return this->_value; 
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
	return ;
}