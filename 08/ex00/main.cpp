/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:06:33 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 11:03:49 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	try {
		std::cout << "vector: " << *easyfind(vec, 5) << std::endl;
		std::cout << "vector: " << *easyfind(vec, 9) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int> lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	try {
		std::cout << "list: " << *easyfind(lst, 5) << std::endl;
		std::cout << "list: " << *easyfind(lst, 9) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	} 

	std::deque<int> deq;
	for (int i = 9; i > 0; i--)
		deq.push_front(i);
	try {
		std::cout << "deque: " << *easyfind(deq, 5) << std::endl;
		std::cout << "deque: " << *easyfind(deq, 9) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
/*
Iterators Overview
Iterator: An object that allows traversal through the elements of a container.
Random Access Iterator: Supports direct access to any element (e.g., std::vector).
Bidirectional Iterator: Supports traversal forwards and backwards (e.g., std::list).
Forward Iterator: Supports traversal only forwards (e.g., std::forward_list).

Container Details

std::vector
Data Storage: Contiguous memory.
Access: Direct access to elements via index.
Methods: begin(), end(), std::find().
Iterator Type: Random Access Iterator.
Behavior: Fast access and iteration, but inserting/removing elements can be slow due to potential reallocation.

std::list
Data Storage: Doubly linked list.
Access: Sequential access; no direct access via index.
Methods: begin(), end(), std::find().
Iterator Type: Bidirectional Iterator.
Behavior: Efficient insertion/removal of elements, but slower access compared to std::vector.

std::deque
Data Storage: Double-ended queue with multiple memory blocks.
Access: Direct access to elements via index.
Methods: begin(), end(), std::find().
Iterator Type: Random Access Iterator.
Behavior: fast insertion and removal at both ends, slower access compared to std::vector.
*/