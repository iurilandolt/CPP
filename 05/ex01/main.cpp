/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:07:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/28 15:24:46 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat b1("Bureaucrat1", 1);
		Bureaucrat b2("Bureaucrat2", 150);
		Form f1("Form1", 0);
		Form f2("Form2", 151);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}