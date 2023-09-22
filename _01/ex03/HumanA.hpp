/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:12:55 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:12:56 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__

class HumanA {
    private:
        std::string _name;
        const Weapon& _weapon;

    public:
        HumanA(const std::string& humanName, const Weapon& weapon);
        void attack(void);
		~HumanA(void);
};
#endif