/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:01:45 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 16:01:46 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

class Zombie {
    private:
        std::string _name;
    public:
	 	Zombie();
        Zombie(std::string _name);
        void announce(void) const;
		void set_name(std::string name);
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif
