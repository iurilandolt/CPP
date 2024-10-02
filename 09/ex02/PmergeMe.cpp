/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:39:57 by rlandolt          #+#    #+#             */
/*   Updated: 2024/10/02 10:44:55 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

template <typename T>
void printContainer(T &container) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(std::vector<std::string> &args) {
	if (args.size() < 2)
		throw std::invalid_argument("Not enough arguments");
	double time_to_insert;
	double time_to_sort;
	time_to_insert = insertTimer(&PmergeMe::insertElements<std::vector<int> >, _vector, args);
	std::cout << "Unsorted: ";	
	printContainer(_vector);
	time_to_sort = sortTimer(&PmergeMe::fordJohnsonVector, _vector);
	std::cout << "Sorted: ";
	printContainer(_vector);
	std::cout << "Time to insert elements in vector: " << std::fixed << std::setprecision(2) << time_to_insert << " microseconds" << std::endl;
	std::cout << "Time to sort vector: " << std::fixed << std::setprecision(2) << time_to_sort << " microseconds" << std::endl;
	time_to_insert = insertTimer(&PmergeMe::insertElements<std::deque<int> >, _deque, args);
	std::cout << "Unsorted: ";
	printContainer(_deque);
	time_to_sort = sortTimer(&PmergeMe::fordJohnsonDeque, _deque);
	std::cout << "Sorted: ";
	printContainer(_deque);
	std::cout << "Time to insert elements in deque: " << std::fixed << std::setprecision(2) << time_to_insert << " microseconds" << std::endl;
	std::cout << "Time to sort deque: " << std::fixed << std::setprecision(2) << time_to_sort << " microseconds" << std::endl;
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
void PmergeMe::insertElements(T &container, std::vector<std::string> &args) {
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
double PmergeMe::insertTimer(T1 func, T2 &container, std::vector<std::string> &args) {
	std::clock_t c_start = std::clock();
	(*func)(container, args);
	std::clock_t c_end = std::clock();
	double duration_in_seconds = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC;
	double duration_in_microseconds = duration_in_seconds * 1e6;
	return duration_in_microseconds;
}

void PmergeMe::fordJohnsonVector(std::vector<int> &container) {
	int n = container.size();
	if (n <= 1)
		return;
	std::vector<int> left;
	std::vector<int> right;
	std::vector<int>::iterator it = container.begin();
	while (it != container.end()) {
		if (std::distance(it, container.end()) > 1) {
			if (*it < *(it + 1)) {
				right.push_back(*it);
				left.push_back(*(it + 1));
			}
			else {
				right.push_back(*(it + 1));
				left.push_back(*it);
			}
			std::advance(it, 2);
		}
		else {
			right.push_back(*it);
			++it;
		}
	}
	fordJohnsonVector(left);
	for (std::vector<int>::iterator jit = right.begin(); jit != right.end(); ++jit) {
		std::vector<int>::iterator pos = std::lower_bound(left.begin(), left.end(), *jit);
		left.insert(pos, *jit);
	}
	std::copy(left.begin(), left.end(), container.begin());
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &container) {
	int n = container.size();
	if (n <= 1)
		return;
	std::deque<int> left;
	std::deque<int> right;
	std::deque<int>::iterator it = container.begin();
	while (it != container.end()) {
		if (std::distance(it, container.end()) > 1) {
			if (*it < *(it + 1)) {
				right.push_back(*it);
				left.push_back(*(it + 1));
			}
			else {
				right.push_back(*(it + 1));
				left.push_back(*it);
			}
			std::advance(it, 2);
		}
		else {
			right.push_back(*it);
			++it;
		}
	}
	fordJohnsonDeque(left);
	for (std::deque<int>::iterator jit = right.begin(); jit != right.end(); ++jit) {
		std::deque<int>::iterator pos = std::lower_bound(left.begin(), left.end(), *jit);
		left.insert(pos, *jit);
	}
	std::copy(left.begin(), left.end(), container.begin());
}

template <typename T1, typename T2>
double PmergeMe::sortTimer(T1 func, T2 &container) {
	std::clock_t c_start = std::clock();
	(*func)(container);
	std::clock_t c_end = std::clock();
	double duration_in_seconds = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC;
	double duration_in_microseconds = duration_in_seconds * 1e6;
	return duration_in_microseconds;
}

/* */

template <typename T>
static void mergeSort(T &container) {
	if (container.size() <= 1)
		return;
	typename T::iterator mid = container.begin() + container.size() / 2;
	T left(container.begin(), mid);
	T right(mid, container.end());
	mergeSort(left);
	mergeSort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
}

// recurrence relation: [ J(n) = J(n-1) + 2 \cdot J(n-2) ] with initial conditions : [J(0) = 0][J(1) = 1]
template <typename T>
static T genJacob(T container, int nbr) {
	T temp;
	temp.push_back(0);
	temp.push_back(1);
	for (int i = 2; i < nbr; ++i) {
		int next = temp[i - 1] + 2 * temp[i - 2];
		if (next < 0 || next > std::numeric_limits<int>::max())
			break;
		temp.push_back(next);
	}
	(void)container;
	return temp;
}

template <typename T>
static void insertionSort(T &container) {
	typename T::iterator it, jt;
	typename std::iterator_traits<typename T::iterator>::value_type key;
	T temp = genJacob(container, container.size());
	// iter every element in container
	for (it = container.begin(); it != container.end(); ++it) {
		key = *it; // set key to current element
		jt = it;   // initialize jt to element to be shifted
		for (int j = temp.size() - 1; j >= 0; --j) { // reverse iter jacobsthal sequence
			if (temp[j] < std::distance(container.begin(), it)) { // if jacobsthal number is less than distance from begin to it
				while (jt != container.begin() && *(jt - 1) > key) {					 // while jt is not at begin and previous element is greater than key decrement jt
					*jt = *(jt - 1); // jt is equal to previous element (shift right)
					std::advance(jt, -1);
				}
				*jt = key; // Insert key at correct position
				break;
			}
		}
	}
}