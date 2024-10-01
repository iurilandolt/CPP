/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:39:57 by rlandolt          #+#    #+#             */
/*   Updated: 2024/10/01 12:16:54 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<std::string> &args) {
	if (args.size() < 2)
		throw std::invalid_argument("Not enough arguments");
	insertTimer(&PmergeMe::insertElements<std::vector<int> >, _vector, args, "Vector");
	insertTimer(&PmergeMe::insertElements<std::deque<int> >, _deque, args, "Deque");
	std::cout << "Unsorted: " << std::endl;
	printContainer(_vector, _deque);
	sortTimer(&PmergeMe::fordJohnson<std::vector<int> >, _vector, "Vector");
	sortTimer(&PmergeMe::fordJohnson<std::deque<int> >, _deque, "Deque");
	std::cout << "Sorted: " << std::endl;
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
	printTime(c_start, c_end, type, "insert", container.size());
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
	for (it = container.begin(); it != container.end(); ++it) {
		key = *it;
		jt = it;
		for (int j = temp.size() - 1; j >= 0; --j) {
			if (temp[j] < std::distance(container.begin(), it)) {
				while (jt != container.begin() && *(jt - 1) > key) {
					*jt = *(jt - 1); // Shift the element right
					std::advance(jt, -1);
				}
				*jt = key; // Insert key at correct position
				break;
			}
		}
	}
}

template <typename T>
void PmergeMe::fordJohnson(T &container) {
	int n = container.size();
	if (n <= 1)
		return;
	T left;
	T right;
	typename T::iterator it = container.begin();
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
		} // there is an odd number of elements
		else {
			right.push_back(*it);
			++it;
		}
	}
	fordJohnson(left);
	insertionSort(right);
	T merged(right.begin(), right.end());
	std::merge(right.begin(), right.end(), left.begin(), left.end(), container.begin());
}

template <typename T1, typename T2>
void PmergeMe::sortTimer(T1 func, T2 &container, std::string type) {
	std::clock_t c_start = std::clock();
	(*func)(container);
	std::clock_t c_end = std::clock();
	printTime(c_start, c_end, type, "sort", container.size());
}

void printContainer(std::vector<int> &v, std::deque<int> &d) {
	std::vector<int>::iterator vit = v.begin();
	std::deque<int>::iterator dit = d.begin();
	std::cout << std::setw(10) << "Vector     | Deque" << std::endl;
	while (vit != v.end() && dit != d.end()) {
		std::cout << std::left << std::setw(10) << *vit
				  << " | " << std::right << std::setw(10) << *dit << std::endl;
		std::advance(vit, 1);
		std::advance(dit, 1);
	}
	std::cout << std::endl;
}

void printTime(std::clock_t c_start, std::clock_t c_end, std::string type, std::string action, int size) {
	double duration_in_seconds = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC;
	double duration_in_microseconds = duration_in_seconds * 1e6;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Time to " << action << " " << size << " elements for " << type << " : " << duration_in_microseconds << " us" << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
}

// template <typename T>
// static void mergeSort(T &container) {
// 	if (container.size() <= 1)
// 		return;
// 	typename T::iterator mid = container.begin() + container.size() / 2;
// 	T left(container.begin(), mid);
// 	T right(mid, container.end());
// 	mergeSort(left);
// 	mergeSort(right);
// 	std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
// }

// template <typename T>
// static void insertionSort(T &container) {
// 	typename T::iterator it, jt;
// 	typename std::iterator_traits<typename T::iterator>::value_type key;
// 	for (it = container.begin(); it != container.end(); ++it) {
// 		key = *it;
// 		jt = it;
// 		while (jt != container.begin() && *(jt - 1) > key) {
// 			*jt = *(jt - 1); // Shift the element right
// 			std::advance(jt, -1);
// 		}
// 		*jt = key; // Insert key at correct position
// 	}
// }

// template <typename T>
// static void insertionSort(T &container) {
// 	typename T::iterator it;
// 	typename std::iterator_traits<typename T::iterator>::value_type key;
// 	for (it = container.begin() + 1; it != container.end(); ++it) {
// 		key = *it;
// 		typename T::iterator pos = std::lower_bound(container.begin(), it, key);
// 		std::copy_backward(pos, it, it + 1);
// 		*pos = key;
// 	}
// }

// template <typename T>
// static void ft_merge(T &container, typename T::iterator left, typename T::iterator mid, typename T::iterator right) {
// 	T temp;
// 	typename T::iterator i = left;
// 	typename T::iterator j = mid;
// 	while (i != mid && j != right) {
// 		if (*i <= *j) {
// 			temp.push_back(*i);
//			std::advance(i, 1);
// 		}
// 		else {
// 			temp.push_back(*j);
// 			std::advance(j, 1);
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

// void PmergeMe::fordJohnsonVector(std::vector<int> &container)
// {
// 	int n = container.size();
// 	if (n <= 1)
// 		return;
// 	std::vector<int> left;
// 	std::vector<int> right;
// 	std::vector<int>::iterator it = container.begin();
// 	while (it != container.end())
// 	{
// 		if (std::distance(it, container.end()) > 1)
// 		{
// 			if (*it < *(it + 1))
// 			{
// 				right.push_back(*it);
// 				left.push_back(*(it + 1));
// 			}
// 			else
// 			{
// 				right.push_back(*(it + 1));
// 				left.push_back(*it);
// 			}
// 			std::advance(it, 2);
// 		} // there is an odd number of elements
// 		else
// 		{
// 			right.push_back(*it);
// 			++it;
// 		}
// 	}
// 	fordJohnsonVector(left);
// 	insertionSort(right);
// 	std::merge(right.begin(), right.end(), left.begin(), left.end(), container.begin());
// }

// void PmergeMe::fordJohnsonDeque(std::deque<int> &container)
// {
// 	int n = container.size();
// 	if (n <= 1)
// 		return;
// 	std::deque<int> left;
// 	std::deque<int> right;
// 	std::deque<int>::iterator it = container.begin();
// 	while (it != container.end())
// 	{
// 		if (std::distance(it, container.end()) > 1)
// 		{
// 			if (*it < *(it + 1))
// 			{
// 				right.push_back(*it);
// 				left.push_back(*(it + 1));
// 			}
// 			else
// 			{
// 				right.push_back(*(it + 1));
// 				left.push_back(*it);
// 			}
// 			std::advance(it, 2);
// 		} // there is an odd number of elements
// 		else
// 		{
// 			right.push_back(*it);
// 			++it;
// 		}
// 	}
// 	fordJohnsonDeque(left);
// 	insertionSort(right);
// 	std::merge(right.begin(), right.end(), left.begin(), left.end(), container.begin());
// }