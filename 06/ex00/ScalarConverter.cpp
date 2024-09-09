/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:33 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/09 19:12:26 by rlandolt         ###   ########.fr       */
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

void ScalarConverter::convert(std::string const & str) {
	std::string tmp = sanitize(str);
	if (tmp.empty()) {
		std::cout << "Error: empty string" << std::endl;
		return;
	}
	
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


