/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:07:56 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/18 11:19:17 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	
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
		
	}
	return (*this);
}