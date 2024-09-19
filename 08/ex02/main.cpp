/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:10:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/19 22:12:30 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

// test with chars

int main(void) {
	{	
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << std::endl;

		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		
		MutantStack<int> s(mstack);
		while (!s.empty()) {
			std::cout << s.top() << std::endl;
			s.pop();
		}
		std::cout << std::endl;
	}
	{	
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator itl = lst.begin();
		std::list<int>::iterator itle = lst.end();
		++itl;
		--itl;
		std::cout << std::endl;
		while (itl != itle) {
			std::cout << *itl << std::endl;
			++itl;
		}
	}
	return 0;
}