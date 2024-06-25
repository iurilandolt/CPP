/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:47 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 13:28:18 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    this->_type = src._type;
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << this->getType() << " meows..." << std::endl;
}