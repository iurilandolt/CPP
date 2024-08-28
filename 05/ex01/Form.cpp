/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:10:27 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/28 15:23:40 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _grade(-1), req_to_sign(1), req_to_exec(1), _signed(false) {
	std::cout << "Form created" << std::endl;
}

Form::Form(std::string const &name, int grade) : _name(name), _grade(grade), req_to_sign(1), req_to_exec(1), _signed(false) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Form " << _name << " created" << std::endl;
}

Form::~Form() {
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form::Form(Form const &src) : _name(src._name), _grade(src._grade), req_to_sign(src.req_to_sign), req_to_exec(src.req_to_exec), _signed(src._signed) {
	std::cout << "Form " << _name << " created by copy" << std::endl;
}

Form &Form::operator=(Form const &src) {
	_signed = src._signed;
	return *this;
}

std::string const &Form::getName() const {
	return _name;
}

int Form::getReqGrade() const {
	return _grade;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}