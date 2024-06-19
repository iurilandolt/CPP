/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClaṕTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:01:50 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 23:13:01 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
    std::cout << "ClapTrap " << _name << " attacks " << target 
        << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
}