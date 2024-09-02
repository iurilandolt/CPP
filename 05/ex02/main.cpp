/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:53:16 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/02 13:35:31 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	AForm *f1; // 145 137
	try {
		Bureaucrat b1("Bureaucrat_a", 146);
		f1 = new ShrubberyCreationForm("Form_a");
		std::cout << b1 << std::endl;
		std::cout << *f1 << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (f1)
		delete f1;
	std::cout << std::endl;
	AForm *f2;
	try {
		Bureaucrat b2("Bureaucrat_b", 137);
		f2 = new ShrubberyCreationForm("Form_b");
		std::cout << b2 << std::endl;
		std::cout << *f2 << std::endl;
		b2.signForm(*f2);
		b2.executeForm(*f2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (f2)
		delete f2;
	std::cout << std::endl;
	AForm *f3; // 72 45
	try {
		Bureaucrat b3("Bureaucrat_c", 72);
		f3 = new RobotomyRequestForm("Form_c");
		std::cout << b3 << std::endl;
		std::cout << *f3 << std::endl;
		b3.signForm(*f3);
		b3.executeForm(*f3);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (f3)
		delete f3;
	std::cout << std::endl;
	AForm *f4;
	try {
		Bureaucrat b4("Bureaucrat_d", 45);
		f4 = new RobotomyRequestForm("Form_d");
		std::cout << b4 << std::endl;
		std::cout << *f4 << std::endl;
		b4.signForm(*f4);
		b4.executeForm(*f4);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (f4)
		delete f4;
	return 0;
}