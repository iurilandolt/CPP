/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:39:48 by rlandolt          #+#    #+#             */
/*   Updated: 2024/10/01 12:14:36 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <ctime>
#include <vector>
#include <deque>
#include <set>
#include <iterator>
#include <algorithm>

class PmergeMe {
	public:
		PmergeMe(std::vector<std::string> &args);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe & operator=(PmergeMe const &src);
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		PmergeMe();

		template <typename T>
		static void insertElements(T &container, std::vector<std::string> &args);
		template <typename T1, typename T2>
		void insertTimer(T1 func, T2 &container, std::vector<std::string> &args, std::string msg);
		
		template <typename T1, typename T2>
		void sortTimer(T1 func, T2 &container, std::string type);
		template <typename T>
		static void fordJohnson(T &container);
		
		// static void fordJohnsonVector(std::vector<int> &container);
		// static void fordJohnsonDeque(std::deque<int> &container);
};

void printContainer(std::vector<int> &v, std::deque<int> &d);
void printTime(std::clock_t c_start, std::clock_t c_end, std::string type, std::string action, int size);

#endif