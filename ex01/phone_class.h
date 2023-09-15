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

#ifndef PHONE_CLASS_H
#define PHONE_CLASS_H

class Contact{
	private:
		std::string name;
		std::string lastName;
		std::string PhoneNumber;
		std::string nickname;
		std::string darkSecret;
	public:
		// name.setName();

// 		The contact fields are: first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
	// void	setContact()
	// {

	// }
};

class PhoneBook {
    public:
		Contact contacts[8];
		int	count;
		//funcio afegir contact
		void addContact(std::string name, std::string lastName, std::string phoneNumber, std::string nickname, std::string darkSecret);
    // It can store a maximum of 8 contacts. If the user tries to add a 9th contact,// replace the oldest one by the new one

};
#endif
