/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:48:32 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/11 23:19:46 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	//std::cout << "PhoneBook Constructor called" << std::endl;
}

PhoneBook::~PhoneBook() {
	//std::cout << "PhoneBook Destructor called" << std::endl;
}

void	PhoneBook::displayInfo() {
	std::cout << "-------------<< PHONEBOOK >>---------------" << std::endl;
	std::cout << " ADD     - Add a new contact            " << std::endl;
	std::cout << " SEARCH  - Display and search contacts  " << std::endl;
	std::cout << " EXIT    - Exit PhoneBook               " << std::endl;
}

void	PhoneBook::displayEntries() {
	if (this->entry[0].index == -1) {
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	else {
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << std::setw(10) << "     Index";
		std::cout << "|" << std::setw(10) << "First Name";
		std::cout << "|" << std::setw(10) << " Last Name";
		std::cout << "|" << std::setw(10) << "  Nickname" << std::endl;
		for (int i = 0; i < SIZE; i++)
			if (this->entry[i].index > -1)
				this->entry[i].displayEntry();
	}
}

void	PhoneBook::addEntry() {
	static int	i = 0;

	if (i == SIZE)
		i = 0;
	if (!this->entry[i].updateEntry(i))
		std::cout << "Invalid input" << std::endl;
}

void	PhoneBook::searchEntry() {
	std::string	input;
	int			index;

	if (this->entry[0].index == -1)
		return ;
	else {
		std::cout << "Enter contact index" << std::endl <<  ">";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ;
		}
		try {
			index = std::stoi(input);
		}
		catch (std::exception &e) {
			std::cout << "Invalid index" << std::endl;
			return ;
		}
		if (index < 0 || index > SIZE - 1 || this->entry[index].index == -1) {
			std::cout << "Invalid index" << std::endl;
			return ;
		}
		this->entry[index].displayDetail();
	}
}
