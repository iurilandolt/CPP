/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:20:40 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 20:45:53 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {
	last_pos = _vector.begin();
}

Span::Span(unsigned int n) : _size(n) {
	if (n > 50000)
		throw overSizedException();
	_vector.reserve(n);
	last_pos = _vector.begin();
}

Span::Span(Span const &src) : _size(src._size) {
	*this = src;
}

Span::~Span(void) {
}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		const_cast<unsigned int &>(_size) = rhs._size;
		_vector.clear();
		_vector = rhs._vector; // create new vector with same values
		last_pos = rhs.last_pos;
	}
	return *this;
}

int &Span::operator[](unsigned int n) {
	if (n >= _size)
		throw OutOfBoundsException();
	return _vector[n];
}

void Span::addNumber(int n) {
	if (_vector.size() < _size) {
		_vector.push_back(n);
		last_pos = _vector.end();
	}
	else
		throw spanFullException();
}

int Span::shortestSpan(void) {
	if (_vector.size() < 2)
		throw std::logic_error("Cannot find span with less than 2 numbers");
	int min = *std::min_element(_vector.begin(), _vector.end());
	int next = std::numeric_limits<int>::max();
	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	
	std::vector<int>::iterator it = copy.begin() + 1;
	next = *it;
	std::cout << "beetween: " << min << " and -> " << next << std::endl;
	return next - min;
}

int Span::longestSpan(void) {
	if (_vector.size() < 2)
		throw std::logic_error("Cannot find span with less than 2 numbers");
	int max = *std::max_element(_vector.begin(), _vector.end());
	int min = *std::min_element(_vector.begin(), _vector.end());
	std::cout << "beetween: " << max << " and -> " << min << std::endl;
	return max - min;
}

// do this using a range of iterators?
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
		const_cast<unsigned int &>(_size) = _vector.size();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Span::printSpan(void) { // use for each ?
	std::vector<int>::iterator it = _vector.begin();
	while (it != _vector.end()) {
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

const char *Span::spanFullException::what() const throw() {
	return "Span is full";
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
	std::vector<int>::iterator it = _vector.begin();
	std::set<int> seen;
	while (it != _vector.end()) {
		if (seen.find(*it) != seen.end())
			it = _vector.erase(it);
		else {
			seen.insert(*it);
			it++;
		}
	}
} */