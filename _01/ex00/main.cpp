/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:45:02 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 15:45:04 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zombie("Brains Zombie");
    zombie.announce();

    std::cout << "----- NEW ZOMBIE -----" << std::endl;

    Zombie* ptrZombie = nullptr; 
    ptrZombie = newZombie("newZombie");
    ptrZombie->announce();

    std::cout << "----- RANDOM CHUMP -----" << std::endl;

    randomChump("RandomZombie");

    delete ptrZombie;
    return 0;
}
