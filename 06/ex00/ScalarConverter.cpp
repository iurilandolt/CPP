/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:33 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/09 16:23:02 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(std::string const & str) {
	std::string tmp = str;

	if (tmp.size() > 1) {
		while (!tmp.empty() && std::isspace(tmp.front()))
			tmp.erase(tmp.begin());
	}
	if (tmp.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return;
	}

	try {
		std::cout << "char: " << std::to_string(tmp[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(std::stoi(tmp.c_str())) << std::endl;
		std::cout << "float: " << static_cast<float>(std::stof(tmp.c_str())) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(std::stod(tmp.c_str())) << std::endl;
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	//std::cout << "char: " << getChar(str) << std::endl;
	//std::cout << "int: " << getInt(str) << std::endl;
	//std::cout << "float: " << getFloat(str) << std::endl;
	//std::cout << "double: " << getDouble(str) << std::endl;
}

/* ß */