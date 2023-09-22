/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:37:16 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:37:17 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int main()
{
    // A string variable initialized to "HI THIS IS BRAIN".
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;

	//  stringREF: A reference to the string.
    std::string& stringREF = str;

    std::cout << "---- ADRESS PRINITNG -----" << std::endl;
    std::cout << "Adress string is: " << &str << std::endl;
    std::cout << "Adress stringPTR is: " << stringPTR << std::endl;
    std::cout << "Adress stringREF is:: " << &stringREF << std::endl;

    std::cout << "---- VALUES PRINITNG -----" << std::endl;
    std::cout << "String value is: " << str << std::endl;
    std::cout << "StringPTR value is: " << *stringPTR << std::endl;
    std::cout << "StringREF value is:: " << stringREF << std::endl;
    return (0);
}