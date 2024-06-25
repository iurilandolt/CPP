/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:10:32 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 14:26:49 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("empty") {
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const std::string type) : _type(type) {
    std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src) {
    std::cout << "AAnimal assignation operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

//void AAnimal::makeSound() const {
//    std::cout << this->getType() << " makes a sound" << std::endl;
//}

std::string AAnimal::getType() const {
    return (this->_type);
}