/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:55:40 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/11 20:11:07 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int size, void (*func)(T&)) {
	for (int i = 0; i < size; i++) {
		func(array[i]);
	}
	std::cout << std::endl;
}

template <typename T>
void print(T &i) {
	std::cout << i << ", "; 
}

#endif