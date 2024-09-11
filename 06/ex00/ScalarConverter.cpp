/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:33 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/11 13:41:07 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {
	(void)src;
	return *this;
}

std::string ScalarConverter::sanitize(std::string const & src) {
	std::string tmp = src;
	while (!tmp.empty() && std::isspace(tmp[0]) && tmp.size() > 1)
			tmp.erase(tmp.begin());
	if (tmp.size() > 1) {
		std::string::size_type pos = tmp.find_first_of(" \t\n\v\f\r");
		if (pos != std::string::npos)
			tmp.erase(pos);
	}
	return tmp;
}

void ScalarConverter::parse(std::string const & src) {
	std::string::const_iterator it = src.begin();
	if (*it == '+' || *it == '-')
		++it;
	while (it != src.end() && isdigit(*it)) {
		++it;
		if (*it == '.') {
			++it;
			break;
		}
	}
	while (it != src.end() && isdigit(*it))
		++it;
	if (!isdigit(*it) && it != src.end()) {
		if (*it != 'f')
			throw std::invalid_argument("Invalid argument");
		++it;
		if (it != src.end())
			throw std::invalid_argument("Invalid argument");	
	}
}

bool ScalarConverter::checkPseudoLiteral(std::string const & str) {
	if (str.compare("nan") == 0 || str.compare("nanf") == 0) {
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
	double raw = 0;
	try {
		if (tmp.length() == 1 && !isdigit(tmp[0]) && isprint(tmp[0]))
			raw = static_cast<double>(tmp[0]);
		else {
			parse(tmp);
			//raw = ft_stod(tmp);
			//raw = std::stod(tmp);
			raw = std::strtod(tmp.c_str(), NULL);
		}
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(1);
	getChar(raw);
	getInt(raw);
	getFloat(raw);
	getDouble(raw);
	std::cout.unsetf(std::ios_base::fixed);
}

char ScalarConverter::getChar(double raw) {
	std::cout << "char: ";
	try {	
		if (raw < std::numeric_limits<char>::min() || raw > std::numeric_limits<char>::max()) {
			std::cout << "Impossible" << std::endl;
			return 0;
		}
		else if (raw < 32 || raw > 126) {
			std::cout << "Non displayable" << std::endl;
			return 0;
		}
		char c = static_cast<char>(raw);
		std::cout << c << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what();
	}
	return 0;
}

int ScalarConverter::getInt(double raw) {
	std::cout << "int: ";
	try {
		if (raw < std::numeric_limits<int>::min() || raw > std::numeric_limits<int>::max())
			std::cout << "Impossible" << std::endl;
		else {
			int i = static_cast<int>(raw);
			std::cout << i << std::endl;
			return i;
		}
	} catch (std::exception & e) {
		std::cout << e.what();
	}
	return 0;
}

float ScalarConverter::getFloat(double raw) {
	std::cout << "float: ";
	try {
		if (raw < std::numeric_limits<float>::min() || raw > std::numeric_limits<float>::max()
			|| raw == std::numeric_limits<float>::infinity() || raw == -std::numeric_limits<float>::infinity())
			std::cout << "Impossible" << std::endl;
		else {
			float f = static_cast<float>(raw);
			std::cout << f << "f" << std::endl;
			return f;
		}
	} catch (std::exception & e) {
		std::cout << e.what();
	}
	return 0;
}

double ScalarConverter::getDouble(double raw) {
	std::cout << "double: ";
	try {
		if (raw < std::numeric_limits<double>::min() || raw > std::numeric_limits<double>::max()
			|| raw == std::numeric_limits<double>::infinity() || raw == -std::numeric_limits<double>::infinity())
			std::cout << "Impossible" << std::endl;
		else {
			double d = static_cast<double>(raw);
			std::cout << d << std::endl;
			return d;
		}
	} catch (std::exception & e) {
		std::cout << e.what();
	}
	return 0;
}

