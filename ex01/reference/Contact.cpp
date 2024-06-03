/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:35:17 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/16 14:26:17 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	// std::cout << "Contact: Constructor called" << std::endl;
	return ;
}

Contact::~Contact(void) {
	// std::cout << "Contact: Destructor called" << std::endl;
	return ;
}

std::string	Contact::getPhoneNumber(void) {
	std::string phoneNumber = "";
	/* bool valid = false;

	while (!valid)
	{ */
		phoneNumber = getInput("* Phone Number: ");
		/* if (isValidPhoneNumber(phoneNumber))
			valid = true;
		else
			std::cout << "\033[91mInvalid phone number, try again.\033[39m" << std::endl;
	} */
	return (phoneNumber);
}

void	Contact::createContact(void) {
	std::cin.ignore();
	std::cout << ">> Creating Contact, please fill in the following fields:" << std::endl;
	this->firstName = getInput("* First Name: ");
	this->lastName = getInput("* Last Name: ");
	this->nickame = getInput("* Nickname: ");
	this->phoneNumber = this->getPhoneNumber();
	this->darkestSecret = getInput("* Darkest Secret: ");
}

std::string	Contact::formatString(std::string str) {
	if (str.length() > 10)
		return (str.substr(0,9) + '.');
	return str;
}

void	Contact::bookFormat(int index) {
	if (this->firstName.empty())
		return ;
	std::cout << std::setw(10) << index + 1;
	std::cout << "|" << std::setw(10) << this->formatString(this->firstName);
	std::cout << "|" << std::setw(10) << this->formatString(this->lastName);
	std::cout << "|" << std::setw(10) << this->formatString(this->nickame) << std::endl;
}

void	Contact::displayContact(void) {
	if (!this->firstName[0])
	{
		std::cout << "\033[91mInvalid contact index.\033[39m" << std::endl << std::flush;
		return ;
	}
	std::cout << std::endl;
	std::cout << "| First Name: " << this->firstName << std::endl;
	std::cout << "| Last Name: " << this->lastName << std::endl;
	std::cout << "| Nickname: " << this->nickame << std::endl;
	std::cout << "| Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "| Darkest Secret: " << this->darkestSecret << std::endl;
	std::cout << std::endl;
}
