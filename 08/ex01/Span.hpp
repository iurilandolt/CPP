/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:54 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/19 11:48:43 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>
#include <exception>

#include <ctime>
#include <cstdlib>

#define MAX_UINT std::numeric_limits<unsigned int>::max()
#define MAX_OBJ 500000

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);
		Span &operator=(Span const &rhs);
		int &operator[](unsigned int n);
		void addNumber(int n);
		int shortestSpan(void);
		int longestSpan(void);
		void populate(unsigned int n);
		template <typename T>
		void populate_from(T &container, typename T::iterator begin, typename T::iterator end);
		void printSpan(void);
	private:
		unsigned int const _size;
		std::vector<int>_vector;
};

template <typename T>
void Span::populate_from(T &container, typename T::iterator begin, typename T::iterator end)
{
	(void)container;
	if (_size < 1)
		throw std::invalid_argument("Invalid size");
	if (_size == 2 && *begin == *end)
		throw std::invalid_argument("Both values are the same, span is 0");
	for (typename T::iterator it = begin; it != end; ++it)
	{
		if (*it > std::numeric_limits<int>::max() || *it < std::numeric_limits<int>::min())
			throw std::overflow_error("Overflow");
		addNumber(*it);
	}
	const_cast<unsigned int &>(_size) = _vector.size();
}

#endif