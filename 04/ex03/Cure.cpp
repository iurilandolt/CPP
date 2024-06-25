/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:35:34 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 21:35:56 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::~Cure() {
}

Cure::Cure(Cure const &src) {
    *this = src;
}

Cure &Cure::operator=(Cure const &src) {
    if (this != &src)
        _type = src._type;
    return (*this);
}

AMateria *Cure::clone() const {
    return (new Cure(*this));
}

AMateria *Cure::clone() const {
    return (new Cure(*this));
}