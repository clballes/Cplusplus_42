/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:14:28 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:14:29 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef __WEAPON_H__
#define __WEAPON_H__

class Weapon {
    private:
        std::string _type;

    public:
        Weapon(const std::string& initialType);
        const std::string& getType() const;
        void setType(const std::string& newType);
		~Weapon();
};
#endif
