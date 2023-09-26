/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:41:03 by clballes          #+#    #+#             */
/*   Updated: 2023/09/26 12:41:04 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl harl;
	std::string level;

	if (argc == 2)
	{
		level = argv[1];
		harl.complain(level);
	}
	else
		std::cout << "Incorrect number arguments, it has to be the executable and one parameter" << std::endl;
    return 0;
}
