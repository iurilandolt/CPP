/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:11:17 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/20 23:51:26 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " is built!" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " is destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    *this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return (*this);
}

void FragTrap::highFivesGuys(void) {
    if (_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " is dead and can't high five!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " wants to high five everyone!" << std::endl;
}

void FragTrap::printStats() const {
    std::cout << "FragTrap " << _name << " stats:" << std::endl;
    std::cout << "HP: " << _hitPoints << std::endl;
    std::cout << "Energy: " << _energyPoints << std::endl;
    std::cout << "Attack Damage: " << _attackDamage << std::endl;
}