/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:45 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 19:39:31 by rlandolt         ###   ########.fr       */
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

bool Fixed::operator>(const Fixed &src) const {
    return (this->_value > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) const {
    return (this->_value < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const {
    return (this->_value >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const {
    return (this->_value <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const {
    return (this->_value == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const {
    return (this->_value != src.getRawBits());
}

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
