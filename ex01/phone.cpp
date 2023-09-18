/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:40:44 by clballes          #+#    #+#             */
/*   Updated: 2023/09/15 15:40:46 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_class.hpp"
#include "contact_class.hpp"
#include <iostream>
#include <sstream>


PhoneBook::PhoneBook()
{
	count = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void PhoneBook::checkContact()
{
	if (count == 8)
	{
		for(int i = 0; i < 7; i++)
		{
			contacts[i] = contacts[i + 1];
		}
		count--;
	}
	contacts[count].addContactInfo();
	count++;
};

void PhoneBook::search()
{
    std::string index;
	int value;

	std::cout << "Which number contact do you want to display: ";
    std::cin >> index;
    value = std::stoi(index);
	// for (int i = 0; i < 8; i++) {
	// 			std::string firstName = contacts[i].getName(); // Assuming getName returns the first name
	// 			std::cout << "Contact " << i + 1 << " First Name: " << firstName << std::endl;
	// 		}
	for(int i = 0; i < 8; i++)
	{
		if ((value - 1) == i)
		{
			std::string hola = contacts[i].getName();
			// contacts[i]
			std::cout << hola << std::endl;

			// std::cout << "" << value << "|" << _name << "|" << _lastname << "|" << nickname << std::endl;
		}
	}
}
