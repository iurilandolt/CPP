/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:20:17 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/19 11:54:13 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	
	// std::vector <int> test;
	// for (int i = 0; i < 500; i++) {
	// 	test.push_back(i);
	// }
	
	try {
		Span sp(MAX_OBJ);
		// sp.populate_from(test, test.begin(), test.end());
		sp.populate(MAX_UINT);
		sp.printSpan();
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}