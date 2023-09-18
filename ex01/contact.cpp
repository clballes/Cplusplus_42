/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:40:44 by clballes          #+#    #+#             */
/*   Updated: 2023/09/15 15:40:46 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact_class.hpp"
#include <iostream>

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void Contact::addContactInfo(void)
{
	std::string UserInfo;
	std::cout << "First Name: ";
	std::cin >> this->_name;
	std::cout << "Last Name: ";
	std::cin >> this->_lastName;
	std::cout << "Phone Number: ";
	std::cin >> this->_PhoneNumber;
	std::cout << "Nickname: ";
	std::cin >> this->_nickname;
	std::cout << "Your darkest secret: ";
	std::cin >> this->_darkSecret;
	std::cout << "Thanks for completing the form! contact added! :)" << std::endl;
}

// std::string getName() const {
//         return _name;
//     }

std::string Contact::getName()
{
    return _name;
}
