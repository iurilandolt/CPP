/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:18:39 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/14 20:16:52 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl destructor called" << std::endl;
}

void Harl::debug() {
	std::cout << "Debug: 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
}

void Harl::info() {
	std::cout << "Info : You didn't put enough bacon in my burger! If you did." << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	Harl::fptr fptr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++) {
		if (levels[i].compare(level) == 0) {
			(this->*fptr[i])();
			return;
		}
	}
	std::cout << "** Unrecognizale gibberish... **" << std::endl;
}
