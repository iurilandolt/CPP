/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:21:44 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/20 23:09:22 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " is built!" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " is destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    *this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return (*this);
}

void ScavTrap::attack(std::string const &target) {
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " is dead and can't attack!" << std::endl;
        return;
    }
    if (_energyPoints < 1) {
        std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " 
        << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode." << std::endl;
}

void ScavTrap::printStats() const {
    std::cout << "ScavTrap " << _name << " stats:" << std::endl;
    std::cout << "HP: " << _hitPoints << std::endl;
    std::cout << "Energy: " << _energyPoints << std::endl;
    std::cout << "Attack Damage: " << _attackDamage << std::endl;
}