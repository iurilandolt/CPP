/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:21:51 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 13:53:26 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
    try {
        this->brain = new Brain();
    } catch (std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
    }
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat &src) : AAnimal(src) {
        std::cout << "Cat copy constructor called" << std::endl;
    this->_type = src._type;
    try {
        this->brain = new Brain(*src.brain);
    } catch (std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
        this->brain = NULL;
    }
}

Cat &Cat::operator=(const Cat &src) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
        this->brain = src.brain;
    }
    return (*this);
}

void Cat::makeSound() const {
    std::cout << this->getType() << " meows..." << std::endl;
}

Brain *Cat::getBrain() const {
    return (this->brain);
}