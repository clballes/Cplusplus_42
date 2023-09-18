/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:40:26 by clballes          #+#    #+#             */
/*   Updated: 2023/09/15 15:40:28 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phone_class.hpp"
#include "contact_class.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string userInput;
    while (1)
	{
        std::cout << "Enter 'ADD' to add a contact, 'SEARCH' to search, or 'EXIT' to exit: ";
        std::cin >> userInput;

		if(!std::cin)
			break ;
        if (userInput == "ADD")
			phoneBook.checkContact();
        else if (userInput == "SEARCH")
			phoneBook.search();
        else if (userInput == "EXIT") {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        else
            std::cout << "Invalid choice. Please enter 'ADD', 'SEARCH', or 'EXIT'." << std::endl;
    }
    return (0);
}
