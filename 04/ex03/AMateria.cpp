/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:26:31 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 21:32:41 by rlandolt         ###   ########.fr       */
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
        _type = src._type;
    return (*this);
}

std::string const &AMateria::getType() const {
    return (_type);
}