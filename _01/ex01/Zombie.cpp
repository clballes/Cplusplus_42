/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:01:30 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 16:01:31 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "create called: " << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : _name(name) 
{
	return ;
}	

void	Zombie::set_name(std::string name)
{
	this->_name = name;
	return ;
}
void    Zombie::announce() const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

 Zombie::~Zombie()
 {
    std::cout << "destructor called: " << this->_name << std::endl;
 }
