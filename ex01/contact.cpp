/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:30 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/05 14:57:46 by rlandolt         ###   ########.fr       */
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

void	Contact::displayDetail() {
	std::cout << "First Name: " << this->name << std::endl;
	std::cout << "Last Name: " << this->surname << std::endl;
	std::cout << "Nickname: " << this->handle << std::endl;
	std::cout << "Phone Number: " << this->number << std::endl;
}

void	Contact::clipInput(std::string &input) {
	int pos;
	input.erase(0, input.find_first_not_of(" \t"));
	pos = input.find_first_of(" \t");
	if (pos != std::string::npos)
		input.erase(pos);
}

std::string	Contact::setValue(std::string field)
{
	std::string value;

	value = "";
	while (value == "") {
		std::cout << "Enter "; std::cout << field << std::endl <<  ">";
		std::getline (std::cin,value);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (value.clear(), value);
		}
	}
	this->clipInput(value);
	return (value);
}

std::string Contact::setNumber() {
	std::string number;
	int nbr;

	number = "";
	while (number == "") {
		std::cout << "Enter Phone Number" << std::endl <<  ">";
		std::getline (std::cin,number);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (number.clear(), number);
		}
		this->clipInput(number);
		try {
			nbr = std::stol(number);
		}
		catch (const std::invalid_argument&) {
			std::cout << "Could not convert to a valid number" << std::endl;
			return (number.clear(), number);
		}
		catch (const std::out_of_range&) {
			std::cout << "Please enter a smaller number" << std::endl;
			return (number.clear(), number);
		}
	}
	return (number);
}

void	Contact::updateEntry(int &index) {
	std::string name;
	std::string surname;
	std::string handle;
	std::string number;

	name = this->setValue("Name");
	if (name.empty())
		return ;
	surname = this->setValue("Surname");
	if (surname.empty())
		return ;
	handle = this->setValue("Nickname");
	if (handle.empty())
		return ;
	number = this->setNumber();
	if (number.empty())
		return ;

	this->index = index++;
	this->name = name;
	this->surname = surname;
	this->handle = handle;
	this->number = number;
}
