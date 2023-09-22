/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:11:26 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 16:11:27 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
	{
        return nullptr;
    }
	Zombie* arr = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		arr[i].set_name(name);
	}
    return arr;
}
