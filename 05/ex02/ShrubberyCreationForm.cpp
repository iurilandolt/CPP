/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:54:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/02 13:28:53 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	_type = SHRUBBERY;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137) {
	_type = SHRUBBERY;
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

// Copy constructor and operator= overload cant access private members to copy them
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src) {
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
	this->_target = src._target;
	this->_type = src._type;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	clearForExecution(executor);
	std::cout << "ShrubberyCreationForm is being executed by " << executor.getName() << std::endl;
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str()); // add argument std::ios::app to append to file instead of overwriting
	if (!file.is_open()) {
		std::cerr << "could not create output file" << std::endl;
		return;
	}
	file << "               ,@@@@@@@,\n";
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	file << "       |o|        | |         | |\n";
	file << "       |.|        | |         | |\n";
	file << "   \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	file.close();
}