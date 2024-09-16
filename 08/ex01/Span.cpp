/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:20:40 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 19:04:43 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {
	last_pos = _array.begin();
}

Span::Span(unsigned int n) : _size(n) {
	if (n > 10000)
		throw overSizedException();
	_array.reserve(n);
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
		throw OutOfBoundsException();
}

void Span::populate(unsigned int n)
{
	try {
		if (n > MAX_UINT) 
			throw overSizedException();
		srand(time(NULL));
		std::set<int> seen;
		for (unsigned int i = 0; i < _size ; i++) {
			int nbr = rand() % n;
			if (seen.find(nbr) == seen.end()) {
				addNumber(nbr);
				seen.insert(nbr);
			}
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Span::printSpan(void) { // use for each ?
	std::vector<int>::iterator it = _array.begin();
	while (it != _array.end()) {
		std::cout << *it << std::endl;
		it++;
	}
}

const char *Span::OutOfBoundsException::what() const throw() {
	return "Out of bounds";
}

const char *Span::overSizedException::what() const throw() {
	return "Size is too big";
}

/* void Span::populate(unsigned int n) {
	try {
		if (n > MAX_UINT)
			throw overSizedException();
		srand(time(NULL));
		for (unsigned int i = 0; i < _size ; i++) {
			addNumber(rand() % n);
		}
		removeDuplicates();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Span::removeDuplicates(void) {
	std::vector<int>::iterator it = _array.begin();
	std::set<int> seen;
	while (it != _array.end()) {
		if (seen.find(*it) != seen.end())
			it = _array.erase(it);
		else {
			seen.insert(*it);
			it++;
		}
	}
} */