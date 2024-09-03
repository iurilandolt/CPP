/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:22:31 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/03 12:09:49 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &src) {
	*this = src;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &src) {
	(void)src;
	return *this;
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
	int i;
	std::string lib[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (i = 0; i < 3; i++) {
		if (lib[i].compare(name) == 0)
			break;
	}
	switch (i) {
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			throw FormNotFoundException();
	}
}