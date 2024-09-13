/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:20:26 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/13 13:51:35 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {

}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = T();
}

template <typename T>
Array<T>::Array(Array const &src) : _size(src._size) {
	if (this != &src)
		*this = src;
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}


template <typename T>
Array<T> &Array<T>::operator=(Array const &src) {
	if (this != &src) {
		const_cast<unsigned int&>(_size) = src._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
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

template <typename T>
void Array<T>::iter(void (*func)(T&)) {
	for (unsigned int i = 0; i < _size; i++)
		func(_array[i]);
	std::cout << std::endl;
}
