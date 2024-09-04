/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:10:27 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/04 11:10:23 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _req_to_sign(150), _req_to_exec(150), _signed(false) {
	std::cout << "Form created" << std::endl;
}

Form::Form(std::string const &name, int sign_grade, int exec_grade) : 
	_name(name), _req_to_sign(sign_grade), _req_to_exec(exec_grade), _signed(false) {
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	std::cout << "Form " << _name << " created" << std::endl;
}

Form::~Form() {
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form::Form(Form const &src) : _name(src._name), _req_to_sign(src._req_to_sign), _req_to_exec(src._req_to_exec), _signed(src._signed) {
	std::cout << "Form " << _name << " created by copy" << std::endl;
}

Form &Form::operator=(Form const &src) {
	_signed = src._signed;
	return *this;
}

std::string const &Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _req_to_sign;
}

int Form::getExecGrade() const {
	return _req_to_exec;
}

bool Form::isSigned() const {
	return _signed;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > _req_to_sign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream & operator<<(std::ostream &os, Form const &obj) {
	os << "Form " << obj.getName() << " requires grade " << obj.getSignGrade() << " to sign and grade " << obj.getExecGrade() << " to execute";
	return os;
}