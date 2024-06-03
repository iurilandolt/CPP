/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:48:32 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/03 16:00:21 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook Constructor called" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook Destructor called" << std::endl;
}

void PhoneBook::Display() {
	std::cout << " ADD     - Add a new contact             " << std::endl;
	std::cout << " SEARCH  - Search for a specific contact " << std::endl;
	std::cout << " EXIT    - Exit the program              " << std::endl;
}
