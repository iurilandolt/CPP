/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:33 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/10 18:15:29 by rlandolt         ###   ########.fr       */
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

/* double ScalarConverter::ft_stod(std::string const & src) {
	std::istringstream iss(src);
	double d;
	iss >> d;
	return d;
} */

std::string ScalarConverter::sanitize(std::string const & src) {
	std::string tmp = src;
	//while (!tmp.empty() && std::isspace(tmp.front()) && tmp.size() > 1)
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
	std::cout << "Input: " << tmp << std::endl;
	std::cout << std::endl;
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
	std::cout << "Char: " << getChar(raw) << std::endl;
	std::cout << "Int: " << getInt(raw) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Float: " << getFloat(raw) << "f" << std::endl;
	std::cout << "Double: " << raw << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
}

char ScalarConverter::getChar(double raw) {
	try {
		//if (raw < CHAR_MIN || raw > CHAR_MAX)
		if (raw < std::numeric_limits<char>::min() || raw > std::numeric_limits<char>::max()) 
			throw std::invalid_argument("Impossible");
		else if (raw < 32 || raw > 126)
			throw std::invalid_argument("Non displayable");
		char c = static_cast<char>(raw);
		return c;
	} catch (std::exception & e) {
		std::cout << e.what();
	}
	return 0;
}

int ScalarConverter::getInt(double raw) {
	try {
		//if (raw < INT_MIN || raw > INT_MAX)
		if (raw < std::numeric_limits<int>::min() || raw > std::numeric_limits<int>::max())
			throw std::invalid_argument("Impossible");
		int i = static_cast<int>(raw);
		return i;
	} catch (std::exception & e) {
		std::cout << e.what();
	}
	return 0;
}

float ScalarConverter::getFloat(double raw) {
	try {
		//if (raw <  -FLT_MIN || raw > FLT_MAX)
		if (raw < std::numeric_limits<float>::min() || raw > std::numeric_limits<float>::max() ||
			raw == std::numeric_limits<float>::infinity() || raw == -std::numeric_limits<float>::infinity())
			throw std::invalid_argument("Impossible");
		float f = static_cast<float>(raw);
		return f;
	} catch (std::exception & e) {
		std::cout << e.what();
	}
	return 0;
}

double ScalarConverter::getDouble(double raw) {
	try {
		//if (raw < -DBL_MIN || raw > DBL_MAX)
		if (raw < std::numeric_limits<double>::min() || raw > std::numeric_limits<double>::max() ||
			raw == std::numeric_limits<double>::infinity() || raw == -std::numeric_limits<double>::infinity())
			throw std::invalid_argument("Impossible");
		return raw;
	} catch (std::exception & e) {
		std::cout << e.what();
	}
	return 0;
}

