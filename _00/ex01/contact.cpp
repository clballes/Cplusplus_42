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
#include <string>

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void Contact::addContactInfo(void) {
    std::cin.ignore();
	do {
    	std::cout << "First Name: ";
        std::getline(std::cin, this->_name);
		if(!std::cin)
			break ;
        if (this->_name.empty()) {
            std::cerr << "Error: First Name cannot be empty. Please try again: ";
        }
    } while (this->_name.empty());
    do {
    	std::cout << "Last Name: ";
        std::getline(std::cin, this->_lastName);
        if(!std::cin)
			break ;
		if (this->_lastName.empty()) {
            std::cerr << "Error: Last Name cannot be empty. Please try again: ";
        }
    } while (this->_lastName.empty());

    do {
    	std::cout << "Phone Number: ";
        std::getline(std::cin, this->_PhoneNumber);
        if(!std::cin)
			break ;
		if (this->_PhoneNumber.empty()) {
            std::cerr << "Error: Phone Number cannot be empty. Please try again: ";
        }
    } while (this->_PhoneNumber.empty());

    do {
    	std::cout << "Nickname: ";
        std::getline(std::cin, this->_nickname);
		if(!std::cin)
			break ;
        if (this->_nickname.empty()) {
            std::cerr << "Error: Nickname cannot be empty. Please try again: ";
        }
    } while (this->_nickname.empty());

    do {
    	std::cout << "Your darkest secret: ";
        std::getline(std::cin, this->_darkSecret);
		if(!std::cin)
			break ;
        if (this->_darkSecret.empty()) {
            std::cerr << "Error: Darkest Secret cannot be empty. Please try again: ";
        }
    } while (this->_darkSecret.empty());

    std::cout << "Thanks for completing the form! Contact added! :)" << std::endl;
}


std::string Contact::getName()
{
    return _name;
}

std::string Contact::getLastName()
{
    return _lastName;
}

std::string Contact::getNickname()
{
    return _nickname;
}
