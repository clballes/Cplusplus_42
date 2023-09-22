/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:13:13 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:13:14 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& humanName) : _name(humanName), _weapon(nullptr)
{
	std::cout << "constructor called human B" << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon& humanWeapon)
{
        this->_weapon = &humanWeapon;
}

HumanB::~HumanB()
{
	std::cout << "destructor called HUMAN B" << std::endl;

}

void HumanB::attack()
{
    if (this->_weapon != nullptr)
    {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    } 
    else 
    {
        std::cout << this->_name << " is unarmed and cannot attack." << std::endl;
    }
}
