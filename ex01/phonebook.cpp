/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:48:32 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/05 00:35:22 by rlandolt         ###   ########.fr       */
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
	std::cout << "-------------------------------------------" << std::endl;
}

void	PhoneBook::addEntry() {
	static int	i = 0;

	if (i == SIZE)
		i = 0;
	this->entry[i].updateEntry(i);
}
