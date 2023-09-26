/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:39:30 by clballes          #+#    #+#             */
/*   Updated: 2023/09/26 10:39:31 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef __HARL_H__
#define __HARL_H__

class Harl {
    private:
        void _debug( void );
        void _info( void );
        void _warning( void );
        void _error( void);
		static void (Harl::*f[4])(void);
		static const std::string str[4];
    public:
        Harl();
        void complain( std::string level );
        ~Harl();
};
#endif
