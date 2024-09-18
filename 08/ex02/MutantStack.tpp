/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:07:56 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/18 11:56:34 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : _size(0) {
	_deq[0] = T();
}

template <typename T>
MutantStack<T>::MutantStack(unsigned int n) : _deq(n), _size(n) {
	for (unsigned int i = 0; i < _size; i++)
		_deq[i] = T();
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) {
	if (this != &src)
		*this = src;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src) {
	if (this != &src) {
		_deq.clear();
		_deq = src._deq;
		_size = src._size;
	}
	return (*this);
}

/*
empty
size
back
push_back
pop_back

+

begin
end

+ 

empty
size
top
push
emplace
pop
swap
*/