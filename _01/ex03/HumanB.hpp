/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:13:23 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:13:24 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef __HUMAN_B_H__
#define __HUMAN_B_H__

class HumanB {
    private:
        std::string _name;
        Weapon* _weapon;
    public:
        HumanB(const std::string& humanName);
        void setWeapon( Weapon& humanWeapon);
        void attack();
        ~HumanB();
};
#endif
