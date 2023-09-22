/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:14:20 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:14:21 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(const std::string& initialType) : _type(initialType) {
	std::cout << "constructor called" << std::endl;
	return ;
}

const std::string& Weapon::getType() const
{
    return this->_type;
}

void Weapon::setType(const std::string& newType)
{
    this->_type = newType;
	return ;
}

Weapon::~Weapon()
{
	std::cout << "destructor called" << std::endl;
	return ;
}