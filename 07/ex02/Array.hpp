/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:20:22 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/12 21:55:18 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array &operator=(Array const &src);
		T &operator[](unsigned int i);
		
		unsigned int size() const;
		void iter(void (*func)(T&));

	private:
		T *_array;
		unsigned int const _size;
		class OutOfBoundsException : public std::exception {
			public:
				const char *what() const throw();
		};
};

template <typename T>
void print(T &i) {
	std::cout << i << ", "; 
}

#include "Array.tpp"

#endif