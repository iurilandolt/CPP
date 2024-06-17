/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:31:58 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/17 13:21:26 by iurilandolt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

const int Fixed::_fBits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
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
    if (this != &src) {
        this->_value = src._value;
    }
    return (*this);
}

