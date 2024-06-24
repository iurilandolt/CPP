/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:10:32 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 14:26:49 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("empty") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const std::string type) : _type(type) {
    std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

void Animal::makeSound() const {
    std::cout << this->getType() << " makes a sound" << std::endl;
}

std::string Animal::getType() const {
    return (this->_type);
}