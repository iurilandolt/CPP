/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:44:44 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/11 12:48:20 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::~Serializer() {

}

Serializer::Serializer(Serializer const & src) {
    *this = src;
}

Serializer & Serializer::operator=(Serializer const & src) {
    (void)src; return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    try {
		return reinterpret_cast<uintptr_t>(ptr);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 0;
}

Data* Serializer::deserialize(uintptr_t raw) {
    try {
		return reinterpret_cast<Data*>(raw);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 0;
}