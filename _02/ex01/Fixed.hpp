/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:19:36 by clballes          #+#    #+#             */
/*   Updated: 2023/09/26 13:19:37 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value; //integer part fixed point
		static const int _fractBits; //integer part for fract bits
	public:
		Fixed( void );
		Fixed( const int num );
		Fixed( const float num );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed & operator=(Fixed const & rhs);

		float toFloat( void ) const;
		int toInt( void ) const;

		float getRawBits( void ) const;
 		void setRawBits( int const raw );
};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif