/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:39:57 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/27 18:40:49 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<std::string> &args) {
	std::clock_t c_start = std::clock();
	std::set<int> seen;
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it) {
		int value;
		std::stringstream ss(*it);
		if ((*it).size() > 10 || !(ss >> value) || value < 0 || value > std::numeric_limits<int>::max())
			throw std::invalid_argument("Invalid argument");
		if (seen.find(value) == seen.end()) {
			seen.insert(value);
			_vector.push_back(value);
			_deque.push_back(value);
			//std::cout << value << std::endl;
		}
		// else
		// 	std::cout << "Duplicate value: " << value << std::endl;
	}

	std::clock_t end = std::clock();
	double duration_in_seconds = static_cast<double>(end - c_start) / CLOCKS_PER_SEC;
	double duration_in_microseconds = duration_in_seconds * 1000000;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Time to insert elements: " << duration_in_microseconds << " microseconds" << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
	
	
	std::vector<int>::iterator vit = _vector.begin();
	std::deque<int>::iterator dit = _deque.begin();
	std::cout << std::setw(10) << "Vector     | Deque" << std::endl;
	while (vit != _vector.end() && dit != _deque.end()) {
		std::cout << std::left << std::setw(10) << *vit 
			<< " | " << std::right << std::setw(10) << *dit << std::endl;
		++vit;
		++dit;
	}
}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
	if (this != &src) {
		_vector = src._vector;
		_deque = src._deque;
	}
	return *this;
}


/*
to add:
insert to vector, print nbr of elements time to finish
insert to deque, print nbr of elements time to finish
removed duplicates from vector, print time to finish // use vectir instead of set?
removed duplicates from deque, print time to finish // use deque instead of set?
sort vector, print time to finish
sort deque, print time to finish
*/