/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:06:39 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/13 15:33:29 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>
//#include <sstream>


#include <iostream>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int target);

class NotFoundException : public std::exception {
	public:
		const char *what() const throw();
};

#include "easyfind.tpp"

#endif