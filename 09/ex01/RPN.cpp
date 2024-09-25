/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:19:49 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/25 17:32:39 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

static bool is_operator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

RPN::RPN(std::string const & str) {
	std::istringstream iss(str);
	std::string token;
	while (iss >> token) {
		if (std::isdigit(token[0])) {
			_digits.push(std::atoi(token.c_str()));
			std::cout << " " << _digits.top() << std::endl;
		} else if (is_operator(token[0])) {
			_operators.push(token[0]);
			std::cout << " " << _operators.top() << std::endl;
		} else {
			throw std::invalid_argument("Invalid expression");
		}
	}
	if (_operators.size() != _digits.size() / 2) {
		throw std::invalid_argument("Invalid expression");
	}
}

// int apply_operator(int a, int b, char op) {
// 	switch (op) {
// 	case '+':
// 		return a + b;
// 	case '-':
// 		return a - b;
// 	case '*':
// 		return a * b;
// 	case '/':
// 		return a / b; //b is 0 ?
// 	default:
// 		throw std::invalid_argument("Unknown operator");
// 	}
// }

RPN::RPN(RPN const & src) {
	*this = src;
}

RPN::~RPN() {}

RPN & RPN::operator=(RPN const & rhs) {
	(void)rhs;
	return *this;
}