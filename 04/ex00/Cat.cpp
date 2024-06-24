/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:21:51 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 13:01:04 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
    std::cout << "Cat type constructor called" << std::endl;
}

Cat::Cat(const Cat &src) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << this->getType() << " meows..." << std::endl;
}