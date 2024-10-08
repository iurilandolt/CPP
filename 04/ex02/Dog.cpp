/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:19:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 18:53:34 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
    try {
        this->brain = new Brain();
    } catch (std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
    }
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &src) : AAnimal(src) {
        std::cout << "Dog copy constructor called" << std::endl;
    this->_type = src._type;
    try {
        this->brain = new Brain(*src.brain);
    } catch (std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
        this->brain = NULL;
    }
}

Dog &Dog::operator=(const Dog &src) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
        *(this->brain) = *(src.brain);
    }
    return (*this);
}

void Dog::makeSound() const {
    std::cout << this->getType() << " barks..." << std::endl;
}

Brain *Dog::getBrain() const {
    return (this->brain);
}