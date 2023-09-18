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


//usat getline
int main()
{
    PhoneBook phoneBook;
    std::string userInput;
    while (1)
	{
        // Prompt the user for input
        std::cout << "Enter 'ADD' to add a contact, 'SEARCH' to search, or 'EXIT' to exit: ";
        // Read user input as a string
        std::cin >> userInput;
        // Check the user's choice and perform the corresponding action
        if (userInput == "ADD")
        {
			phoneBook.checkContact();
        }
        else if (userInput == "SEARCH")
        {
            // std::cout << "You chose to search." << std::endl;
			phoneBook.search();
            // Add your search logic here
        }
        else if (userInput == "EXIT") {
            std::cout << "Exiting the program." << std::endl;
            break;  // Exit the loop and terminate the program
        }
        else {
            std::cout << "Invalid choice. Please enter 'ADD', 'SEARCH', or 'EXIT'." << std::endl;
        }
    }
    return (0);
}
