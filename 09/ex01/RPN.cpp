/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:19:49 by rlandolt          #+#    #+#             */
/*   Updated: 2024/10/01 11:16:17 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}


RPN::RPN(RPN const & src) {
	*this = src;
}

RPN::~RPN() {}

RPN & RPN::operator=(RPN const & src) {
	while (!_digits.empty())
		_digits.pop();
	_digits = src._digits;
	return *this;
}
static bool is_operator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

static int apply_operator(int a, int b, char op) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw std::invalid_argument("Division by zero");
		return a / b;
	default:
		throw std::invalid_argument("Unknown operator");
	}
}

RPN::RPN(std::string const & str) {
	std::istringstream iss(str);
	std::string token;
	int a, b;
	while (iss >> token) {
		if (token.size() > 1)
			throw std::invalid_argument("Invalid expression");
		if (std::isdigit(token[0])) {
			int value;
			std::istringstream digit(token);
			if (!(digit >> value))
				throw std::invalid_argument("Invalid expression");
			_digits.push(value);
		}
		else if (is_operator(token[0])) {
			if (_digits.size() < 2)
				throw std::invalid_argument("Invalid expression");
			b = _digits.top(); 
			_digits.pop();
			a = _digits.top(); 
			_digits.pop();
			_digits.push(apply_operator(a, b, token[0]));
		}
		else
			throw std::invalid_argument("Invalid expression");
	}
	if (_digits.size() != 1)
		throw std::invalid_argument("Invalid expression");
	std::cout << _digits.top() << std::endl;
}