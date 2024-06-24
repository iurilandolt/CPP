/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:19:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 13:00:54 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    std::cout << "Dog type constructor called" << std::endl;
}
Dog::Dog(const Dog &src) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &src) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

void Dog::makeSound() const {
    std::cout << this->getType() << " barks..." << std::endl;
}