/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:55:48 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 14:40:31 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int int_arr[] = {1, 2, 3, 4, 5};
	char char_arr[] = {'a', 'b', 'c', 'd', 'e'};
	std::string str_arr[] = {"one", "two", "three", "four", "five"};

	int *null_ptr = NULL;

	::iter(int_arr, 5, print<int>);
	::iter(char_arr, 5, print<char>);
	::iter(str_arr, 5, print<std::string>);
	::iter(null_ptr, 5, print<int>);

	return 0;
}