/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:49:13 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/30 14:32:19 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(-1) {
	std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

// C++ destroys all objects in scope after an exception occurs, 
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {
	std::cout << "Bureaucrat " << _name << " created by copy" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
	_grade = src._grade;
	std::cout << "Bureaucrat " << _name << " assigned" << std::endl;
	return *this;
}

std::ostream & operator<<(std::ostream &os, Bureaucrat const &obj) {
	os << obj.getName() << " grade " << obj.getGrade();
	return os;
}

std::string const &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form) const {
	std::cout << _name << " signs " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}