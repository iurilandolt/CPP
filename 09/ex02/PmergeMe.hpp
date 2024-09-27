/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:39:48 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/27 18:29:28 by rlandolt         ###   ########.fr       */
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
#include <set> // will be removed

class PmergeMe {
	public:
		PmergeMe(std::vector<std::string> &args);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe & operator=(PmergeMe const &src);
	private:
		PmergeMe();
		std::vector<int> _vector;
		std::deque<int> _deque;
};

#endif