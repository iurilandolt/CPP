/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:20:26 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/11 20:43:50 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
	
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {
	
}

template <typename T>
Array<T>::Array(Array const &src) {
	if (this != &src)
		*this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &src) {
	if (this != &src) {
		delete [] _array;
		_size = src.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw OutOfBoundsException();
	return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (_size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
	return ("Out of bounds");
}