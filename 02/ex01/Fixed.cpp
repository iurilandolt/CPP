/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:45 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 17:04:10 by rlandolt         ###   ########.fr       */
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

// instanciate a new object with the same value as src
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = src._value;
}

// assign the values of the rhs object to the lhs object
Fixed & Fixed::operator=(const Fixed &src) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return (*this);
}

// non member function, define cout behavior for Fixed object
std::ostream & operator<<(std::ostream &os, const Fixed &obj) {
    os << obj.toFloat();
    return (os);
}

//set the value of the object
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

// get the value of the object
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

/*
    to convert a floating point to a fixed point we multiply the float number
    with the base raised to the power of n (n the size of the fractional part)
    to do the opposite we devide
*/
// convert the value of the object to float
float Fixed::toFloat(void) const {
    return ((float)this->_value / (1 << _fBits));
}

// convert the value of the object to int
int Fixed::toInt(void) const {
    return (this->_value >> _fBits);
}
