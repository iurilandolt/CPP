/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:45 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 18:24:28 by rlandolt         ###   ########.fr       */
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
    this->_value = value << _fBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << _fBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed & Fixed::operator=(const Fixed &src) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return (*this);
}

std::ostream & operator<<(std::ostream &os, const Fixed &obj) {
    os << obj.toFloat();
    return (os);
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

int Fixed::getRawBits(void) const {
    return (this->_value);
}

/*
    to convert a floating point to a fixed point we multiply the float number
    with the base raised to the power of n (n the size of the fractional part)
    to do the opposite we devide
*/
float Fixed::toFloat(void) const {
    return ((float)this->_value / (1 << _fBits));
}

int Fixed::toInt(void) const {
    return (this->_value >> _fBits);
}
