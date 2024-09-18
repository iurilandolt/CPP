/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:06:14 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/18 13:06:57 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(unsigned int n);
		MutantStack(MutantStack const &src);
		~MutantStack();
		MutantStack &operator=(MutantStack const &src);
		
		typedef std::deque<int>::iterator it;
		typedef std::deque<int>::const_iterator cit;
		typedef std::deque<int>::reverse_iterator rit;
		typedef std::deque<int>::const_reverse_iterator crit;
		
	private:
		std::deque<T> _deq;
		unsigned int _size;
};


/*
begin
end
const begin
const end
reverse begin
reverse end
const reverse begin
const reverse end
*/


#include "MutantStack.tpp"

#endif