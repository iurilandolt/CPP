/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:48:32 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/04 20:59:42 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook Constructor called" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook Destructor called" << std::endl;
}

void	PhoneBook::displayInfo() {
	std::cout << " ADD     - Add a new contact            " << std::endl;
	std::cout << " SEARCH  - Search for a specific contact" << std::endl;
	std::cout << " EXIT    - Exit the program             " << std::endl;
}

void	PhoneBook::displayEntries() {

	std::cout << "-------------<< PHONEBOOK >>---------------" << std::endl;
	std::cout << std::setw(10) << "Index     ";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name ";
	std::cout << "|" << std::setw(10) << "Nickname  " << std::endl;
	for (int i = 0; i < SIZE; i++)
		if (this->entry[i].index > -1)
			this->entry[i].displayEntry();
}

int	PhoneBook::findSlot() {
	for (int i = 0; i < SIZE; i++) {
		std::cout << i << std::endl;
		if (this->entry[i].index == -1)
			return (i);
	}
	return (0);
}

void	PhoneBook::addEntry() {
	//check slot
	int	i;

	i = findSlot();
	this->entry[i].index = i; // this assignment should be done only in updateEntry  below

	// set name
	this->entry[i].updateEntry();
	// set surname
	// set hande
	// set secret
}
