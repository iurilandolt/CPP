/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:01:50 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/26 12:28:18 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap " << _name << " was built!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " was destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return (*this);
}

void ClapTrap::attack(std::string const &target) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
        return;
    }
    if (_energyPoints < 1) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
        << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    if (amount > _hitPoints) {
        std::cout << "ClapTrap " << _name << " takes " << _hitPoints << " points of damage!" << std::endl;
        std::cout << "ClapTrap " << _name << " died!" << std::endl;
        _hitPoints = 0;
        return;
    }
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is dead and can't be repaired!" << std::endl;
        return;
    }
    if (_energyPoints < 1) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " is being repaired for " << amount << " points!" << std::endl;
    _hitPoints += amount;
    _energyPoints--;
}

void ClapTrap::printStats() const {
    std::cout << "ClapTrap " << _name << " stats:" << std::endl;
    std::cout << "HP: " << _hitPoints << std::endl;
    std::cout << "Energy: " << _energyPoints << std::endl;
    std::cout << "Attack Damage: " << _attackDamage << std::endl;
}