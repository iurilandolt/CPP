/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:06:14 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/19 13:43:36 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(unsigned int n) : std::stack<T>(std::deque<T>(n)) {}
	MutantStack(MutantStack const &src) : std::stack<T>(src) {}
	~MutantStack() {}
	MutantStack &operator=(MutantStack const &src) {
		if (this != &src)
			std::stack<T>::operator=(src);
		return *this;
	}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif