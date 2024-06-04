/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:30 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/04 13:04:26 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
	std::cout << "Contact Constructor called" << std::endl;
	this->index = -1;
	this->name = "empty";
	this->surname = "empty";
	this->handle = "empty";
	this->number = "empty";
	this->secret = "empty";
}

Contact::~Contact() {
	std::cout << "Contact Destructor called" << std::endl;
}

void Contact::displayEntry() {
	std::cout << std::setw(10) << this->index;
	std::cout << "|" << std::setw(10) << this->name;
	std::cout << "|" << std::setw(10) << this->surname;
	std::cout << "|" << std::setw(10) << this->handle << std::endl;
}

std::string Contact::setValue(std::string field)
{
	std::string value;

	return (value);
}

void	Contact::updateEntry() {
	std::string name;
	std::string surname;
	std::string handle;
	std::string secret;

	name = "";
	while (name == "") {
		std::cout << "enter name> ";
		std::cin >> name;
	}
	surname = "";
	while (surname == "") {
		std::cout << "enter surname> ";
		std::cin >> surname;
	}
	while (handle == "") {
		std::cout << "enter handle> ";
		std::cin >> handle;
	}
	this->name = name;
	this->surname = surname;
	this->handle = handle;
}
