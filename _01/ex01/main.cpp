/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:01:56 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 16:01:57 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string zombieName = "VALERIO";

    Zombie* horde = zombieHorde(N, zombieName);
    if (horde)
    {
        for (int i = 0; i < N; ++i)
            horde[i].announce();
    }
	delete [] horde;
    return 0;
}
