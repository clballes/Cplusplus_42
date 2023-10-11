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

class Fixed
{
	private:
		int _value;
		static const int _fractBits;
	public:
		Fixed( void );
		Fixed( Fixed const & src );
		Fixed & operator=(Fixed const & srcs);
		~Fixed( void );
		
		int getRawBits( void ) const;
 		void setRawBits( int const raw );
};

#endif