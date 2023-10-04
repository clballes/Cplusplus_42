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
		int _value;
		static const int _fractBits;
	public:
		Fixed( void );
		Fixed( const int num );
		Fixed( const float num );
		Fixed( Fixed const & src );
		Fixed & operator=(Fixed const & rhs);
		~Fixed( void );

		//comparison operators >, <, >=, <=, == and !=.
		bool operator==(Fixed const & rhs) const;
		bool operator!=(Fixed const & rhs) const;
		bool operator>(Fixed const & rhs) const;
		bool operator>=(Fixed const & rhs) const;
		bool operator<(Fixed const & rhs) const;
		bool operator<=(Fixed const & rhs) const;

		//arithmetic operators
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		//pre increment and post-increment
		Fixed  operator++(void );
		Fixed  operator--(void);
		Fixed  operator++(int);
		Fixed  operator--(int);

		//members public min and maxs
		const static Fixed& min(const Fixed &  a, const Fixed & b );
		const static Fixed& max(const Fixed &  a, const Fixed & b );
		const static Fixed& min( Fixed &  a, Fixed & b );
		const static Fixed& max( Fixed &  a, Fixed & b );

		float 	toFloat( void ) const;
		int 	toInt( void ) const;
		float 	getRawBits( void ) const;
 		void 	setRawBits( int const raw );
};
std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );
#endif