/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:45:10 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/11 19:50:58 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
	int a = 2;
	int b = 3;
	char ac = 'a';
	char bc = 'b';
	std::string as = "str1";
	std::string bs = "str2";

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "ac = " << ac << ", bc = " << bc << std::endl;
	std::cout << "as = " << as << ", bs = " << bs << std::endl;
	std::cout << std::endl;

	::swap(a, b);
	::swap(ac, bc);
	::swap(as, bs);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "ac = " << ac << ", bc = " << bc << std::endl;
	std::cout << "as = " << as << ", bs = " << bs << std::endl;
	std::cout << std::endl;

	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "min(ac, bc) = " << ::min(ac, bc) << std::endl;
	std::cout << "min(as, bs) = " << ::min(as, bs) << std::endl;
	std::cout << std::endl;

	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << "max(ac, bc) = " << ::max(ac, bc) << std::endl;
	std::cout << "max(as, bs) = " << ::max(as, bs) << std::endl;



	return 0;
}