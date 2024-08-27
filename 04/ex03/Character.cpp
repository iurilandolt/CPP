/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:17:48 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/27 12:50:29 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Character::Character(Character const &src) {
	*this = src;
}

Character &Character::operator=(Character const &src) {
	if (this != &src) {
		_name = src._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = src._inventory[i];
		}
	}
	return (*this);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		if (_inventory[idx]) {
			delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4) {
		if (_inventory[idx])
			_inventory[idx]->use(target);
		}
}

std::string const &Character::getName() const {
	return (_name);
}