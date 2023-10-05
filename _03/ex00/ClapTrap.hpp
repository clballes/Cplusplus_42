/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:53:54 by clballes          #+#    #+#             */
/*   Updated: 2023/10/05 14:53:56 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_H__
# define __CLAP_TRAP_H__

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap( void );
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & src);
        ClapTrap & operator=(ClapTrap const & rhs);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        //getters
        std::string getName () const;
        int getHitPoints () const;
        int getEnergyPoints () const;
        int getAttackDamage () const;
};

#endif
