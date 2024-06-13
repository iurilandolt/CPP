/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:45:46 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/13 19:06:40 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon) {
	this->_name = name;
	std::cout << "HumanA constructor called for " << this->_name << " with weapon "
		<< this->_weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA destructor called for " << this->_name << std::endl;
}

void HumanA::attack() {
	if (this->_weapon.getType().empty())
		std::cout << this->_name << " attacks with his bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

