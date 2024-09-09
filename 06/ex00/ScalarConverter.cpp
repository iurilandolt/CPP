/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:33 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/09 12:13:21 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) {
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(std::string const & str) {

	std::cout << "char: " << getChar(str) << std::endl;
	//std::cout << "int: " << getInt(str) << std::endl;
	//std::cout << "float: " << getFloat(str) << std::endl;
	//std::cout << "double: " << getDouble(str) << std::endl;
}

char ScalarConverter::getChar(std::string const & str) {
	
}