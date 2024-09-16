/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:20:17 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/16 20:46:12 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	try {
		Span sp(50000);
		sp.populate(MAX_UINT);
		sp.printSpan();
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}