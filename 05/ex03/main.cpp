/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:53:16 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/04 11:46:43 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm *rrf;

	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		rrf = someRandomIntern.makeForm("presidential pardon", "Some poor Soul");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		rrf = someRandomIntern.makeForm("something weird", "target");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}