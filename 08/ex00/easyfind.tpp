/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:06:36 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/13 15:26:14 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int target) {
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::exception();
	return it;
}

const char *NotFoundException::what() const throw() {
	return "Element not found";
}