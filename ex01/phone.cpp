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

#include "phone_class.h"
#include <iostream>

void PhoneBook::addContact(std::string name, std::string lastName, std::string phoneNumber, std::string nickname, std::string darkSecret)
{
	std::cout << name << " y " << lastName << " " << phoneNumber << " " << nickname << " " << darkSecret << std::endl;
	// if(!name.empty())
	// {
	// 	contacts[0].name = name;
	// 	std::cout << contacts[0].name << std::endl;
	// }
	// std::cout << std::string name, std::string lastName, std::string phoneNumber, std::string nickname, std::string darkSecret << std::endl;
	// if (count < 8)
	// {
	// 	contacts[count++].setContact(name, phoneNumber);
	// } else
	// {
	// 	// Replace the oldest contact (the first one)
	// 	for (int i = 0; i < 7; ++i) {
	// 		contacts[i] = contacts[i + 1];
	// 	}
	// 	contacts[7].setContact(name, phoneNumber);
	// }
}
