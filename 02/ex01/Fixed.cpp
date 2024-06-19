/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:45 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:29:47 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fBits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << Fixed::_fBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << Fixed::_fBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = src._value;
}

Fixed & Fixed::operator=(const Fixed &src) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return (*this);
}

Fixed & Fixed::operator<<(const Fixed &src) {
    std::cout << "Shift operator called" << std::endl;
    this->_value = src.getRawBits();
    return (*this);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

float Fixed::toFloat(void) const {
    return ((float)this->_value / (1 << Fixed::_fBits));
}

int Fixed::toInt(void) const {
    return (this->_value >> Fixed::_fBits);
}