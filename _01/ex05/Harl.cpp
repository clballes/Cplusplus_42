/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:39:19 by clballes          #+#    #+#             */
/*   Updated: 2023/09/26 10:39:20 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::str[4] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

void (Harl::*Harl::f[4])(void) = {
	&Harl::_debug,
	&Harl::_info,
	&Harl::_warning,
	&Harl::_error
};

void Harl::_info()
{
    std::cout << "this is info message" << std::endl;
}

void Harl::_warning()
{
    std::cout << "this is warning message" << std::endl;
}

void Harl::_error()
{
    std::cout << "this is error message" << std::endl;
}

void Harl::_debug()
{
    std::cout << "this is debug message" << std::endl;
}

void Harl::complain( std::string level )
{
	for(int i = 0; i < 4; i++)
	{
		if (level  == (this->str[i]))
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "unknown level: " << level << std::endl;
}

Harl::Harl()
{
       return ;
}

Harl::~Harl()
{
    std::cout << "destructor called" << std::endl;
	return ;
}
