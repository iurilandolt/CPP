/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:55:40 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 14:41:09 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
/*
In C++98 just like in c, there is no built-in way to determine the size of a dynamically allocated array from a pointer alone(except strings?).
For dynamically allocated arrays, you need to rely on the size provided by the user or manage the size information separately.
You can encapsulate the array and its size in a class or struct to ensure the size information is always available.

*/
template <typename T1, typename T2>
void iter(T1 *array, int size, T2 func) {
	if (array == NULL || size < 0) 
		return ;
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