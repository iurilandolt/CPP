/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:53:47 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/20 23:58:01 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(""), FragTrap("") {
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    // this->_hitPoints = FragTrap::_hitPoints;
    // this->_energyPoints = ScavTrap::_energyPoints;
    // this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " is built! Abomination!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->_name << " is destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return (*this);
}

void DiamondTrap::attack(std::string const &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::printStats() const {
    std::cout << "HP: " << FragTrap::_hitPoints << std::endl;
    std::cout << "Energy: " << ScavTrap::_energyPoints << std::endl;
    std::cout << "Attack Damage: " << FragTrap::_attackDamage << std::endl;
}