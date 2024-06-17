/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:27:43 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/17 15:17:27 by iurilandolt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// #include <stdlib.h>

Zombie::Zombie() {
	std::cout << "Default Zombie constructor called" << std::endl;
	this->_name.clear();
}

Zombie::~Zombie() {
	std::cout << "Zombie destructor called for: " << this->_name <<std::endl;
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::itoa(int i) {
	std::string str;
	int		neg;

	neg = 0;
	if (i < 0) {
		neg = 1;
		i = -i;
	}
	while (i > 0) {
		str = (char)(i % 10 + '0') + str;
		i /= 10;
	}
	if (neg)
		str = "-" + str;
	return (str);
}

void	Zombie::setName(std::string name, int i) {
	this->_name = name + "-" + this->itoa(i + 1);
}

Zombie	*zombieHorde(int size, std::string name) {
	Zombie	*horde = new Zombie[size];

	for (int i = 0; i < size; i++) {
		horde[i].setName(name, i);
	}
	return (horde);
}
