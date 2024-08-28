/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:07:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/28 13:48:08 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);
		Bureaucrat b3("b3", 151);
		Bureaucrat b4("b4", 0);
	} 
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat b1("b5", 140);
	try {
		b1.decrementGrade();
	} 
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;
	return 0;
}