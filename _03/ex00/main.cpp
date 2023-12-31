/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:54:11 by clballes          #+#    #+#             */
/*   Updated: 2023/10/05 14:54:12 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob("Albi");
    ClapTrap bob2( bob );

	std::cout << bob2.getHitPoints() << std::endl;

    bob.attack("Christian");
    bob.takeDamage(6);
    bob.beRepaired(3);
    bob.takeDamage(3);
    bob.takeDamage(4);
    bob.takeDamage(4);
    bob.attack("Christian");
    bob.beRepaired(3);
}
