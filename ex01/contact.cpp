/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:30 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/04 21:02:31 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
	std::cout << "Contact Constructor called" << std::endl;
	this->index = -1;
	this->name = "";
	this->surname = "";
	this->handle = "";
	this->number = "";
	this->secret = "";
}

Contact::~Contact() {
	std::cout << "Contact Destructor called" << std::endl;
}

void	Contact::displayEntry() {
	std::cout << std::setw(10) << this->index;
	if (this->name.length() > 10) {
		std::cout << "|" << std::setw(9) << this->name.substr(0, 9);
		std::cout << ".";
	}
	else
		std::cout << "|" << std::setw(10) << this->name.substr(0, 10);
	if (this->surname.length() > 10) {
		std::cout << "|" << std::setw(9) << this->surname.substr(0, 9);
		std::cout << ".";
	}
	else
		std::cout << "|" << std::setw(10) << this->surname.substr(0, 10);
	if (this->handle.length() > 10) {
		std::cout << "|" << std::setw(9) << this->handle.substr(0, 9);
		std::cout << "." << std::endl;
	}
	else
		std::cout << "|" << std::setw(10) << this->handle.substr(0, 10) << std::endl;
}

std::string	Contact::setValue(std::string field)
{
	std::string value;
	std::string alter;

	value = "";
	while (value == "") {
		std::cout << "Enter "; std::cout << field << std::endl;
		std::getline (std::cin,value);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ("");
		}
	}
	return (value);
}

void	Contact::updateEntry() {

	std::string name;
	std::string surname;
	std::string handle;

	name = this->setValue("Name >");
	name.erase(remove_if(name.begin(), name.end(), isspace), name.end());
	if (name.empty())
		return ;
	surname = this->setValue("Surname >");
	surname.erase(remove_if(surname.begin(), surname.end(), isspace), surname.end());
	if (surname.empty())
		return ;
	handle = this->setValue("Nickname >");
	handle.erase(remove_if(handle.begin(), handle.end(), isspace), handle.end());
	if (handle.empty())
		return ;
	//get index from func argument and set it here instead of addEntry
	this->name = name;
	this->surname = surname;
	this->handle = handle;
}
