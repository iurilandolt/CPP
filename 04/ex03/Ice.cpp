/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:31:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/26 14:27:08 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::~Ice() {
}

Ice::Ice(Ice const &src) : AMateria("ice") {
    *this = src;
}

Ice &Ice::operator=(Ice const &src) {
    if (this != &src)
        _type = src._type;
    return (*this);
}

AMateria *Ice::clone() const {
    return (new Ice(*this));
}