/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:39:47 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/16 12:44:02 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	// std::cout << "PhoneBook: Constructor called" << std::endl;
	this->index = 0;
}

PhoneBook::~PhoneBook(void) {
	// std::cout << "PhoneBook: Destructor called" << std::endl;
}

void	PhoneBook::addContact(void) {
	Contact newContact;

	if (this->index == 8)
	{
		std::cout << "\033[91mMax number of contacts reached. Replacing oldest contact.\033[39m" << std::endl;
		this->index = 0;
	}

	newContact.createContact();

	this->contacts[this->index] = newContact;
	this->index++;
	std::cout << "\033[92mContact added!\033[39m" << std::endl;
}

void	PhoneBook::commandList(void) {
	std::cout << "\033[30m\033[107m" << " Available Commands:                  " << "\033[39m\033[49m" << std::endl;
	std::cout << "\033[30m\033[107m" << " ADD     - Save a new contact         " << "\033[39m\033[49m" << std::endl;
	std::cout << "\033[30m\033[107m" << " SEARCH  - Display a specific contact " << "\033[39m\033[49m" << std::endl;
	std::cout << "\033[30m\033[107m" << " EXIT    - Close the phonebook        " << "\033[39m\033[49m" << std::endl;
}

void	PhoneBook::displayPhoneBook(void) {
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
		this->contacts[i].bookFormat(i);
	std::cout << "-------------------------------------------" << std::endl;
}

void	PhoneBook::searchContact(void) {
	int	index = -1;
	this->displayPhoneBook();
	std::cout << ">> Enter the contact index: ";
	std::cin >> index;
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	else if (std::cin.good() && index <= 8 && index > 0)
		this->contacts[index - 1].displayContact();
	else
		std::cout << "\033[91mInvalid contact index.\033[39m" << std::endl << std::flush;
	std::cin.clear();
	std::cin.ignore();
}