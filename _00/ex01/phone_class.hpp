/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_class.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:40:57 by clballes          #+#    #+#             */
/*   Updated: 2023/09/15 15:40:58 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "contact_class.hpp"

#ifndef PHONE_CLASS_H
#define PHONE_CLASS_H

class PhoneBook {
	private:
		Contact contacts[8];
		int	count;
    public:
		PhoneBook();
		~PhoneBook();
		void	checkContact();
		void	search();
};
#endif
