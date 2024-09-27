/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:39:57 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/27 22:49:51 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<std::string> &args) {
	if (args.size() < 2)
		throw std::invalid_argument("Not enough arguments");
	std::cout << "Vector:" << std::endl;
	execTimer(&PmergeMe::populate<std::vector<int> >, _vector, args, "insert");
	std::cout << "Deque:" << std::endl;
	execTimer(&PmergeMe::populate<std::deque<int> >, _deque, args, "insert");
	printContainer(_vector, _deque);
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

template <typename T>
void PmergeMe::populate(T &container, std::vector<std::string> &args) {
	std::set<int> seen;
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it) {
		int value;
		std::stringstream ss(*it);
		if ((*it).size() > 10 || !(ss >> value) || value < 0 || value > std::numeric_limits<int>::max())
			throw std::invalid_argument("Invalid argument");
		if (seen.find(value) == seen.end()) {
			seen.insert(value);
			container.push_back(value);
		} // else its duplicate
	}
}

template <typename T1, typename T2>
void PmergeMe::execTimer(T1 func, T2 &container, std::vector<std::string> &args, std::string msg) {
	std::clock_t c_start = std::clock();
	(*func)(container, args);
	std::clock_t c_end = std::clock();
	double duration_in_seconds = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC;
	double duration_in_microseconds = duration_in_seconds * 1e6;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Time to " << msg << " elements: " << duration_in_microseconds << " us" << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
}

void printContainer(std::vector<int> &v, std::deque<int> &d) {
	std::vector<int>::iterator vit = v.begin();
	std::deque<int>::iterator dit = d.begin();
	std::cout << std::setw(10) << "Vector     | Deque" << std::endl;
	while (vit != v.end() && dit != d.end())
	{
		std::cout << std::left << std::setw(10) << *vit
				  << " | " << std::right << std::setw(10) << *dit << std::endl;
		++vit;
		++dit;
	}
}

/*
to add:
sort vector, print time to finish
sort deque, print time to finish
*/