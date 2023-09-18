/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_class.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:40:57 by clballes          #+#    #+#             */
/*   Updated: 2023/09/15 15:40:58 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

class Contact
{
	private:
		std::string _name;
		std::string _lastName;
		std::string _PhoneNumber;
		std::string _nickname;
		std::string _darkSecret;

	public:
		Contact();
		~Contact();
		void addContactInfo();
		std::string getName();
		std::string getLastName();
		std::string getNickname();
};
#endif
