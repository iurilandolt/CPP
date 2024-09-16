/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:54 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 18:52:08 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <exception>

#include <ctime>
#include <cstdlib>

#define MAX_UINT std::numeric_limits<unsigned int>::max()

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);
		Span &operator=(Span const &rhs);
		Span &operator[](unsigned int n);
		
		void addNumber(int n);
		int shortestSpan(void);
		int longestSpan(void);

		void populate(unsigned int n);
		void printSpan(void);
	private:
		unsigned int _size;
		std::vector<int>_array;
		std::vector<int>::iterator last_pos;
		class OutOfBoundsException : public std::exception {
			public:
				const char *what() const throw();
		};
		class overSizedException : public std::exception {
			public:
				const char *what() const throw();
		};
		void removeDuplicates(void);
};


#endif