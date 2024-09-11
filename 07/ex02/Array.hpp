/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:20:22 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/11 20:45:16 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include "Array.tpp"

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array &operator=(Array const &src);
		T &Array<T>::operator[](unsigned int i) const;
		
		unsigned int size() const;
	private:
		T *_array;
		unsigned int const _size;
		class OutOfBoundsException : public std::exception {
			public:
				const char *what() const throw();
		};
		
};

#endif