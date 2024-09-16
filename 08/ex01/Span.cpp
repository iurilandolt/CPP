/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:20:40 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 12:41:05 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {
	last_pos = _array.begin();
}

Span::Span(unsigned int n) : _size(n) {
	//_array.reserve(n);
	last_pos = _array.begin();
}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span(void) {
}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		_size = rhs._size;
		_array = rhs._array; // create new vector with same values
		last_pos = rhs.last_pos;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_array.size() < _size) {
		_array.push_back(n);
		last_pos = _array.end();
	}
	else
		throw std::exception();
}