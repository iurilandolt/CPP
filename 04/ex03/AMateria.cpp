/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:26:31 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/26 14:39:16 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::~AMateria() {
}

AMateria::AMateria(AMateria const &src) {
    *this = src;
}

AMateria &AMateria::operator=(AMateria const &src) {
    if (this != &src)
        _type = src._type;// while assgining a Materia to another, copying the type doesnt make sense, but we have to do it to pass the test
    return (*this);
}

std::string const &AMateria::getType() const {
    return (_type);
}