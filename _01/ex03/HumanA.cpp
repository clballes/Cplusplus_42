/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:12:38 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:12:39 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(const std::string& humanName, const Weapon& weapon) : _name(humanName), _weapon(weapon) {
	std::cout << "constructor called human A" << std::endl;
	return ;
}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their: " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "destructor called HUMAN A" << std::endl;
	return ;
}