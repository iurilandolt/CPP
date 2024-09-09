/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:33 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/09 19:29:36 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}


std::string ScalarConverter::sanitize(std::string const & src) {
	std::string tmp = src;
	while (!tmp.empty() && std::isspace(tmp.front()) && tmp.size() > 1)
			tmp.erase(tmp.begin());
	if (tmp.size() > 1) {
		std::string::size_type pos = tmp.find_first_of(" \t\n\v\f\r");
		if (pos != std::string::npos)
			tmp.erase(pos);
	}
	return tmp;
}

bool ScalarConverter::checkPseudoLiteral(std::string const & str) {
	if (str.compare("nan") == 0) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	else if (str.compare("+inf") == 0 || str.compare("+inff") == 0 
		|| str.compare("inf") == 0 || str.compare("inff") == 0) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return true;
	}
	else if (str.compare("-inf") == 0 || str.compare("-inff") == 0) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::convert(std::string const & str) {
	std::string tmp = sanitize(str);
	if (tmp.empty()) {
		std::cout << "Error: empty string" << std::endl;
		return;
	}
	if (checkPseudoLiteral(tmp)) 
		return;
	
	std::cout << "Input: " << tmp << std::endl;
	std::cout << std::endl;


	double raw = 0;
	if (tmp.length() == 1 && !isdigit(tmp[0]) && isprint(tmp[0]))
		raw = static_cast<double>(tmp[0]);
	else {
		try {
			raw = std::stod(tmp);
		} catch (std::exception & e) {
			std::cout << "Error: " << e.what() << std::endl;
			return;
		}
	}
	std::cout << raw << std::endl;
}


/* char ScalarConverter::getChar(std::string const & str) {

} */


