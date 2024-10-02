/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:20:29 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/13 13:58:05 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* #include <ctime>
#include <cstdlib> */


int main() {
	Array<int> int_arr(5);
	Array<char> char_arr(5);
	Array<std::string> str_arr(5);

	int_arr.iter(print);
	char_arr.iter(print);
	str_arr.iter(print);
	std::cout << std::endl;
	std::cout << "Int &" << &int_arr << std::endl;
	std::cout << "Char &" << &char_arr << std::endl;
	std::cout << "Str &" << &str_arr << std::endl;
	std::cout << std::endl;

	Array<int> int_cpy(int_arr);
	Array<char> char_cpy = char_arr;
	Array<std::string> str_cpy(str_arr);
	int_cpy.iter(print);	
	char_cpy.iter(print);
	str_cpy.iter(print);
	std::cout << std::endl;
	std::cout << "Int copy &" << &int_cpy << std::endl;
	std::cout << "Char copy &" << &char_cpy << std::endl;
	std::cout << "Str copy &" << &str_cpy << std::endl;
	std::cout << std::endl;

	try  {
		Array<int> a;
		std::cout << a[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Array<char> a(5);
		a[4] = 'a';
		std::cout << a[4] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}

