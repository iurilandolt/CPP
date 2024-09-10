/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:44:44 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/10 18:21:30 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
It's an unsigned integer type exactly the size of a pointer. 
Whenever you need to do something unusual with a pointer 
    - like for example invert all bits (don't ask why) 
you cast it to uintptr_t and manipulate it as a usual integer number, then cast back.


At its core, std::uintptr_t is a versatile unsigned integer type 
designed to store the entire address range of any object in C++,
ensuring portability and precision. 
std::uintptr_t is defined in the <cstdint> header as part of the C Standard Library. 
It was introduced in C99 and C++11 respectively.

https://blog.feabhas.com/2024/02/navigating-memory-in-c-a-guide-to-using-stduintptr_t-for-address-handling/
*/

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
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}