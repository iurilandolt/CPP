/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:54 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/28 15:30:50 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//levels must be uppercase

Harl::Harl() {
	std::cout << "Harl constructor called" << std::endl;
	this->_fptr[0] = &Harl::debug;
	this->_fptr[1] = &Harl::info;
	this->_fptr[2] = &Harl::warning;
	this->_fptr[3] = &Harl::error;
}

Harl::~Harl() {
	std::cout << "Harl destructor called" << std::endl;
}

void Harl::debug(void) {
	std::cout << "DEBUG: 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
}

void Harl::info(void) {
	std::cout << "INFO : You didn't put enough bacon in my burger! If you did." << std::endl;
}

void Harl::warning(void) {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error(void) {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i].compare(level) == 0) {
			(this->*_fptr[i])();
			return;
		}
	}
	std::cout << "** Unrecognizale gibberish... **" << std::endl;
}
