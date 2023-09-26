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
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::_debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
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
