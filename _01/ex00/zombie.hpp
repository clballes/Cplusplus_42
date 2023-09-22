/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:44:47 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 15:44:48 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

class Zombie {
    private:
        std::string _name;

    public:
        Zombie(std::string name);
        std::string getName(void);
        void announce( void );
        ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif
