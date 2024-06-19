/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:26:48 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:26:50 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// #include <stdlib.h>

Zombie::Zombie() {
	std::cout << "Default Zombie constructor called" << std::endl;
	this->_name.clear();
}

Zombie::~Zombie() {
	std::cout << "Zombie destructor called" << this->_name <<std::endl;
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

Zombie	*zombieHorde(int size, std::string name) {
	Zombie	*horde = new Zombie[size];

	for (int i = 0; i < size; i++) {
		horde[i].setName(name);
	}
	return (horde);
}
