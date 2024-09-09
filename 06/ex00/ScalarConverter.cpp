/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:33 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/09 14:27:09 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(std::string const & str) {
	std::string tmp = str;
	std::string::iterator it = tmp.begin();
	bool fractional = false;
	
	if (tmp.length() > 1) {
		while (it != tmp.end() && *it == ' ') {
			tmp.erase(it);
			it++;
		}
		it = tmp.begin();
		if (*it == '+' || *it == '-') {
			it++;
		}
		if (!isdigit(*it)) {
			std::cout << "Error: invalid input 1" << std::endl;
			return ;
		}
		while (it != tmp.end() && isdigit(*it)) {

			it++;
			if (*it == '.') {
				if (fractional) {
					std::cout << "Error: invalid input 2" << std::endl;
					return ;
				}
				fractional = true;
				it++;
			}
		}
		if (it == tmp.end() && (*it != 'f' || !isdigit(*it))) {
			std::cout << "Error: invalid input 3" << std::endl;
			return ;
		}
 
	}
	std::cout << "valid input: " << tmp << std::endl;
	//std::cout << "char: " << getChar(str) << std::endl;
	//std::cout << "int: " << getInt(str) << std::endl;
	//std::cout << "float: " << getFloat(str) << std::endl;
	//std::cout << "double: " << getDouble(str) << std::endl;
}

/* ß */