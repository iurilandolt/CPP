/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:54 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 12:39:03 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

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
	private:
		unsigned int _size;
		std::vector<int> _array;
		std::vector<int>::iterator last_pos;
};

#endif