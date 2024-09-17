/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:20:40 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/17 15:05:26 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {

}

Span::Span(unsigned int n) : _size(n) {
	if (n > MAX_OBJ)
		throw std::invalid_argument("Invalid size");
	_vector.reserve(n);
}

Span::Span(Span const &src) : _size(src._size) {
	*this = src;
}

Span::~Span(void) {
}

Span &Span::operator=(Span const &src) {
	if (this != &src) {
		const_cast<unsigned int &>(_size) = src._size;
		_vector.clear();
		_vector = src._vector; 
	}
	return *this;
}

int &Span::operator[](unsigned int n) {
	if (n >= _size)
		throw std::out_of_range("Out of bounds");
	return _vector[n];
}

void Span::addNumber(int n) {
	if (_size < 1)
		throw std::invalid_argument("Invalid size");
	else if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		throw std::overflow_error("Overflow");
	else if (_vector.size() < _size) {
		_vector.push_back(n);
	}
	else
		throw std::overflow_error("Span is full");
}

int Span::shortestSpan(void) {
	if (_vector.size() < 2)
		throw std::logic_error("Cannot find span with less than 2 numbers");
	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	copy.erase(copy.begin() + 2, copy.end());
	std::cout << "beetween: " << copy.front() << " and -> " << copy.back() << std::endl;
	return copy.back() - copy.front();
}

int Span::longestSpan(void) {
	if (_vector.size() < 2)
		throw std::logic_error("Cannot find span with less than 2 numbers");
	int max = *std::max_element(_vector.begin(), _vector.end());
	int min = *std::min_element(_vector.begin(), _vector.end());
	std::cout << "beetween: " << min << " and -> " << max << std::endl;
	return max - min;
}

void Span::populate(unsigned int n)
{
	if (n > MAX_UINT || _size < 1)
		throw std::invalid_argument("Invalid size");
	if (_size == 2 && _vector[0] == _vector[1])
		throw std::invalid_argument("Both values are the same, span is 0");
	srand(time(NULL));
	std::set<int> seen;
	for (unsigned int i = 0; i < _size; i++) {
		int nbr = (rand() % (2 * n)) - n;
		if (seen.find(nbr) == seen.end()) {
			addNumber(nbr);
			seen.insert(nbr);
		}
	}
	const_cast<unsigned int &>(_size) = _vector.size();
}

template <typename T>
static void print(T &i) {
	std::cout << i << std::endl;
}

void Span::printSpan(void) {
	std::for_each(_vector.begin(), _vector.end(), print<int>);
}

/*
void Span::populate(unsigned int n) {
	if (n > MAX_UINT || _size < 1)
		throw std::invalid_argument("Invalid size");
	if (_size == 2 && _vector[0] == _vector[1])
		throw std::invalid_argument("Both values are the same, span is 0");
	srand(time(NULL));
	std::for_each(_vector.begin(), _vector.end(),[&](int nbr) {
		nbr = (rand() % (2 * n)) - n;
		addNumber(nbr);
	});
	const_cast<unsigned int &>(_size) = _vector.size();
}*/

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