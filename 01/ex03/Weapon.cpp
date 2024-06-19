/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:27:22 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:27:24 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon() {
}

void Weapon::setType(std::string type) {
	this->_type = type;
}

const std::string& Weapon::getType() const {
	return (this->_type);
}
