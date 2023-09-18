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
#include <iomanip>

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

std::string my_strlen(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

void PhoneBook::search()
{
    std::string index;
    int value;

	while (1)
	{
		std::cout << "Which number contact do you want to display: ";
		std::cin >> index;
		value = atoi(index.c_str());
		if (value > 8 || value <= 0)
			std::cerr << "Error: Number must be between 1 and 8!" << std::endl;
		else	
			break ;
	}
	for (int i = 0; i < 8; i++)
	{
		if ((value - 1) == i)
		{
			std::string name = contacts[i].getName();
			name = my_strlen(name);
			std::string lastName = contacts[i].getLastName();
			lastName = my_strlen(lastName);
			std::string nickname = contacts[i].getNickname();
			nickname = my_strlen(nickname);
			std::cout << std::right << std::setw(10) << value << " | " << std::setw(10) << name << " | " << std::setw(10) << lastName << " | " << std::setw(10) << nickname << std::endl;
		}
	}
}