/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:30 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/05 00:28:47 by rlandolt         ###   ########.fr       */
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
	std::string alter;

	value = "";
	while (value == "") {
		std::cout << "Enter "; std::cout << field << std::endl <<  ">";
		std::getline (std::cin,value);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ("");
		}
	}
	this->clipInput(value);
	return (value);
}

void	Contact::updateEntry(int &index) {
	std::string name;
	std::string surname;
	std::string handle;

	name = this->setValue("Name");
	if (name.empty())
		return ;
	surname = this->setValue("Surname");
	if (surname.empty())
		return ;
	handle = this->setValue("Nickname");
	if (handle.empty())
		return ;
	this->index = index++;
	this->name = name;
	this->surname = surname;
	this->handle = handle;
}
