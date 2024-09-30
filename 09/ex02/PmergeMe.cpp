/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:39:57 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/30 14:38:23 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<std::string> &args) {
	if (args.size() < 2)
		throw std::invalid_argument("Not enough arguments");
	insertTimer(&PmergeMe::insertElements<std::vector<int> >, _vector, args, "Vector");
	insertTimer(&PmergeMe::insertElements<std::deque<int> >, _deque, args, "Deque");
	sortTimer(&PmergeMe::sort<std::vector<int> >, _vector, "Vector");
	sortTimer(&PmergeMe::sort<std::deque<int> >, _deque, "Deque");
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
void PmergeMe::insertTimer(T1 func, T2 &container, std::vector<std::string> &args, std::string type) {
	std::clock_t c_start = std::clock();
	(*func)(container, args);
	std::clock_t c_end = std::clock();
	double duration_in_seconds = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC;
	double duration_in_microseconds = duration_in_seconds * 1e6;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Time to insert " << container.size() << " elements for " << type << " : " << duration_in_microseconds << " us" << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
}

// template <typename T>
// static void insertionSort(T &container) {
// 	typename T::iterator it, jt;
// 	typename std::iterator_traits<typename T::iterator>::value_type key;
// 	for (it = container.begin(); it != container.end(); ++it) {
// 		key = *it;
// 		jt = it;
// 		while (jt != container.begin() && *(jt - 1) > key) {
// 			*jt = *(jt - 1); // Shift the element right
// 			--jt;
// 		}
// 		*jt = key; // Insert key at correct position
// 	}
// }

template <typename T>
static void insertionSort(T &container) {
	typename T::iterator it;
	typename std::iterator_traits<typename T::iterator>::value_type key;
	for (it = container.begin() + 1; it != container.end(); ++it) {
		key = *it;
		typename T::iterator pos = std::lower_bound(container.begin(), it, key);
		std::copy_backward(pos, it, it + 1);
		*pos = key;
	}
}

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

template <typename T>
static void fordJohnson(T &container) {
	int n = container.size();
	if (n <= 1)
		return;
	T larger;
	T smaller;
	typename T::iterator it = container.begin();
	while (it != container.end()) {
		if (std::distance(it, container.end()) > 1) {
			if (*it < *(it + 1)) {
				smaller.push_back(*it);
				larger.push_back(*(it + 1));
			}
			else {
				smaller.push_back(*(it + 1));
				larger.push_back(*it);
			}
			std::advance(it, 2);
		} // there is an odd number of elements
		else {
			smaller.push_back(*it);
			++it;
		}
	}
	fordJohnson(larger);
	insertionSort(smaller);
	T merged(smaller.begin(), smaller.end());
	std::merge(smaller.begin(), smaller.end(), larger.begin(), larger.end(), container.begin());
}

template <typename T>
void PmergeMe::sort(T &container) {
	//insertionSort(container);
	//mergeSort(container);
	fordJohnson(container);
}

template <typename T1, typename T2>
void PmergeMe::sortTimer(T1 func, T2 &container, std::string type) {
	std::clock_t c_start = std::clock();
	(*func)(container);
	std::clock_t c_end = std::clock();
	double duration_in_seconds = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC;
	double duration_in_microseconds = duration_in_seconds * 1e6;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Time to sort " << container.size() << " elements for " << type << " : " << duration_in_microseconds << " us" << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
}

void printContainer(std::vector<int> &v, std::deque<int> &d) {
	std::vector<int>::iterator vit = v.begin();
	std::deque<int>::iterator dit = d.begin();
	std::cout << std::setw(10) << "Vector     | Deque" << std::endl;
	while (vit != v.end() && dit != d.end()) {
		std::cout << std::left << std::setw(10) << *vit
				  << " | " << std::right << std::setw(10) << *dit << std::endl;
		++vit;
		++dit;
	}
}

// template <typename T>
// static void ft_merge(T &container, typename T::iterator left, typename T::iterator mid, typename T::iterator right) {
// 	T temp;
// 	typename T::iterator i = left;
// 	typename T::iterator j = mid;
// 	while (i != mid && j != right) {
// 		if (*i <= *j) {
// 			temp.push_back(*i);
// 			++i;
// 		}
// 		else {
// 			temp.push_back(*j);
// 			++j;
// 		}
// 	}
// 	temp.insert(temp.end(), i, mid);
// 	temp.insert(temp.end(), j, right);
// 	std::copy(temp.begin(), temp.end(), left);
// 	(void)container;
// }

// template <typename T>
// void mergeSort(T &container, typename T::iterator left, typename T::iterator right) {
// 	if (std::distance(left, right) > 1) {
// 		typename T::iterator mid = left;
// 		std::advance(mid, std::distance(left, right) / 2);
// 		mergeSort(container, left, mid);
// 		mergeSort(container, mid, right);
// 		ft_merge(container, left, mid, right);
// 		//std::merge(left, mid, mid, right, left);
// 	}
// }