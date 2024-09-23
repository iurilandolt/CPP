/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:40:54 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/23 20:37:10 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename) : _database("data.csv") ,  _infile(filename) {
	if (!_infile.is_open()) {
		throw std::runtime_error("BitcoinExchange: could not open input file");
	}
	if (!_database.is_open()) {
		throw std::runtime_error("BitcoinExchange: could not open database file");
	}
	std::string line;
	while (std::getline(_database, line)) {	
		std::cout << line << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange() : _database("data.csv") {
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
	(void)src;
	return *this;
}