/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:22:31 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/02 14:39:19 by rlandolt         ###   ########.fr       */
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
	if (name == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	else if (name == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (name == "presidential pardon")
		return new PresidentialPardonForm(target);
	else
		throw FormNotFoundException();
}