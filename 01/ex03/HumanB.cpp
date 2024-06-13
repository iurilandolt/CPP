/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:45:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/13 19:04:31 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
	std::cout << "HumanB constructor called for " << this->_name << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanA destructor called." << std::endl;
}

void HumanB::attack() {
	if (this->_weapon && this->_weapon->getType().empty())
		std::cout << this->_name << " attacks with his bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}


