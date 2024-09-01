/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:53:59 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/01 11:54:00 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _type(BASE), _name("default"), _req_to_sign(-1), _req_to_exec(-1), _signed(false)
{
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(std::string const &name, int sign_grade, int exec_grade) : 
	_type(BASE), _name(name), _req_to_sign(sign_grade), _req_to_exec(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	std::cout << "AForm " << _name << " created" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

AForm::AForm(AForm const &src) : _type(src._type), _name(src._name),
	_req_to_sign(src._req_to_sign), _req_to_exec(src._req_to_exec), _signed(src._signed)
{
	std::cout << "AForm " << _name << " created by copy" << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
	_signed = src._signed;
	return *this;
}

std::string const &AForm::getName() const
{
	return _name;
}

std::string AForm::getType() const
{
	switch (_type)
	{
		case PRESIDENTIAL:
			return "Presidential";
		case SHRUBBERY:
			return "Shrubbery";
		case ROBOT:
			return "Robot";
		default:
			return "Base";
	}
}

int AForm::getSignGrade() const
{
	return _req_to_sign;
}

int AForm::getExecGrade() const
{
	return _req_to_exec;
}

bool AForm::isSigned() const
{
	return _signed;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _req_to_sign)
	{
		throw GradeTooLowException();
	}
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _req_to_exec)
	{
		throw GradeTooLowException();
	}
	std::cout << "AForm " << _name << " is a " << getType() << " form and cannot be executed." << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, AForm const &obj)
{
	os << "AForm " << obj.getName() << " of type " << obj.getType() 
		<< " requires grade " << obj.getSignGrade() << " to sign and grade " 
		<< obj.getExecGrade() << " to execute";
	return os;
}