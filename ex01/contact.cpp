/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:30 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/03 20:58:18 by rlandolt         ###   ########.fr       */
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

void Contact::displayEntry(int i) {
	std::cout << std::setw(10) << this->index;
	std::cout << "|" << std::setw(10) << this->name;
	std::cout << "|" << std::setw(10) << this->surname;
	std::cout << "|" << std::setw(10) << this->handle << std::endl;
}
