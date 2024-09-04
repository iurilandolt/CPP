/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:07:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/04 11:39:14 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("b1", 151);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("b2", 150);
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
	} 
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}