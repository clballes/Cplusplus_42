/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:45:37 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 15:45:39 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie zombie(name);
    std::cout << "Zombie created with name: " << name << std::endl;
    zombie.announce();
}