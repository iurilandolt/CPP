/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:45 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 22:56:28 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fBits = 8;

Fixed::Fixed() {
    this->_value = 0;
}

Fixed::Fixed(const int value) {
    this->_value = value << _fBits;
}

Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << _fBits));
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed &src) {
    *this = src;
}

Fixed & Fixed::operator=(const Fixed &src) {
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

float Fixed::toFloat(void) const {
    return ((float)this->_value / (1 << _fBits));
}

int Fixed::toInt(void) const {
    return (this->_value >> _fBits);
}

bool Fixed::operator>(const Fixed &src) const {
    return (this->_value > src._value);
}

bool Fixed::operator<(const Fixed &src) const {
    return (this->_value < src._value);
}

bool Fixed::operator>=(const Fixed &src) const {
    return (this->_value >= src._value);
}

bool Fixed::operator<=(const Fixed &src) const {
    return (this->_value <= src._value);
}

bool Fixed::operator==(const Fixed &src) const {
    return (this->_value == src._value);
}

bool Fixed::operator!=(const Fixed &src) const {
    return (this->_value != src._value);
}

/*
`_value` is an integer that's 256 times larger than the actual number it represents. 
So, when performing arithmetic operations like addition, subtraction, multiplication, or division, 
we need to convert `_value` to the actual number using `toFloat()`. 
If we'd used `_value` directly, the result would be 256 times too large.
*/

Fixed Fixed::operator+(const Fixed &src) const {
    return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const {
    return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const {
    return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const {
    return (Fixed(this->toFloat() / src.toFloat()));
}

/*
The smallest change we can represent in our fixed-point number is 1/2^_fBits, 
or 1/256 if _fbits = 8, which is approximately 0.0039.
*/

Fixed & Fixed::operator++() {
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed & Fixed::operator--() {
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed & Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}
