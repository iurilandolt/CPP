/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:53:16 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/02 14:41:55 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << ">> ShrubberyCreationForm <<" << std::endl;
	AForm *f1; // 145 137
	try {
		Bureaucrat b1("Bureaucrat_a", 146);
		f1 = new ShrubberyCreationForm("Form_a");
		std::cout << b1 << std::endl;
		std::cout << *f1 << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	AForm *f2;
	try {
		Bureaucrat b2("Bureaucrat_b", 137);
		f2 = new ShrubberyCreationForm("Form_b");
		std::cout << b2 << std::endl;
		std::cout << *f2 << std::endl;
		b2.signForm(*f2);
		b2.executeForm(*f2);
		delete f2;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}	
	std::cout << std::endl;
	std::cout << ">> RobotomyRequestForm <<" << std::endl;
	AForm *f3; // 72 45
	try {
		Bureaucrat b3("Bureaucrat_c", 72);
		f3 = new RobotomyRequestForm("Form_c");
		std::cout << b3 << std::endl;
		std::cout << *f3 << std::endl;
		b3.signForm(*f3);
		b3.executeForm(*f3);
		delete f3;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	AForm *f4;
	try {
		Bureaucrat b4("Bureaucrat_d", 45);
		f4 = new RobotomyRequestForm("Form_d");
		std::cout << b4 << std::endl;
		std::cout << *f4 << std::endl;
		b4.signForm(*f4);
		b4.executeForm(*f4);
		delete f4;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << ">> PresidentialPardonForm <<" << std::endl;
	AForm *f5; // 25 5
	try {
		Bureaucrat b5("Bureaucrat_e", 25);
		f5 = new PresidentialPardonForm("Form_e");
		std::cout << b5 << std::endl;
		std::cout << *f5 << std::endl;
		b5.signForm(*f5);
		b5.executeForm(*f5);
		delete f5;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	AForm *f6;
	try {
		Bureaucrat b6("Bureaucrat_f", 5);
		f6 = new PresidentialPardonForm("Form_f");
		std::cout << b6 << std::endl;
		std::cout << *f6 << std::endl;
		b6.signForm(*f6);
		b6.executeForm(*f6);
		delete f6;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}