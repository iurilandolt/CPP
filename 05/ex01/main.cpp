/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:07:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/01 11:31:55 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// grade out of bounds
	try {
		Form f1("Form1", 1, 151);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	// insuficent grade to sign form
	try {		
		Bureaucrat b1("Bob", 2);
		Form f1("Form1", 1, 1);
		b1.signForm(f1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	// correct grade to sign form
	try {
		Bureaucrat b1("Bob", 1);
		Form f1("Form1", 3, 1);
		b1.signForm(f1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}