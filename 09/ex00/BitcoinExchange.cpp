/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:40:54 by rlandolt          #+#    #+#             */
/*   Updated: 2024/10/01 10:50:48 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _database("data.csv") {}

BitcoinExchange::BitcoinExchange(const std::string &filename) : 
	_database("data.csv"), _infile(filename.c_str()), _infile_name(filename) {
	_validateFiles();
	_parseDB();
	_parseInput();
}

BitcoinExchange::~BitcoinExchange() {
	_database.close();
	_infile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
	if (this != &src) {
		_exchange.clear();
		_exchange = src._exchange;
		_infile_name = src._infile_name;
		_database.close();
		_database.open("data.csv");
		_infile.close();
		_infile.open(_infile_name.c_str());
	}
	return *this;
}

void BitcoinExchange::_parseDB(void) {
	std::string line;
	while (std::getline(_database, line)) {
		if (line.compare("date,exchange_rate") == 0)
			continue;
		std::istringstream iss(line);
		std::string date;
		double rate;
		if (std::getline(iss, date, ',') && iss >> rate) {
			if (!validate_format(date)) // date.empty() ?
				throw std::runtime_error("Database error: invalid date format.");
			_exchange[date] = rate;
		}
		// else if (line.size() > 0)
		// 	throw std::runtime_error("Database error: invalid line format");
	}
}

void BitcoinExchange::writeData(std::string &date, double value) {
	std::map<std::string, double>::iterator it = _exchange.lower_bound(date);
	if (it == _exchange.end())
		it = --_exchange.end();
	else if (it == _exchange.begin() && it->first != date) {
		std::cout << "Error: no data available for this date." << std::endl;
		return;
		//it = _exchange.begin();
	}	
	else if (it->first != date)
		--it;
	double exchange_rate = it->second;
	double result = value * exchange_rate;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << date << " => " << value << " = " << static_cast<float>(result) << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
}

static bool input_error(std::string &date, double value) {
	if (value < 0) {
		std::cout << "Error: negative value." << std::endl;
		return true;
	}
	else if (value > 1000) {
		std::cout << "Error: value too high." << std::endl;
		return true;
	}
	if (!validate_format(date) || date.empty()) {
		std::cout << "Error: invalid date format. " << date << std::endl;
		return true;
	}
	return false;
}

void BitcoinExchange::_parseInput(void) {
	std::string line;	
	while (std::getline(_infile, line)) {
		if (line.compare("date | value") == 0)
			continue;
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		std::istringstream iss(line);
		std::string date;
		double value;
		if (std::getline(iss, date, '|') && iss >> value ) {
			if (input_error(date, value))
				continue;
			writeData(date, value);
		}
		else if (line.size() > 0) {
			std::cout << "Error: invalid line format." << std::endl;
		}
	}
}

void BitcoinExchange::_validateFiles(void) {
	if (!_infile.is_open() || !_infile.good() || _infile.bad() || _infile.fail())
		throw std::runtime_error("BitcoinExchange: could not open input file");
	if (!_database.is_open() || !_database.good() || _database.bad() || _database.fail())
		throw std::runtime_error("BitcoinExchange: could not open database file");
}

bool validate_day(int year, int month, int day) {
	int days_per_month[12];
	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	for (int i = 0; i < 12; i++) {
		if (i == 1) {
			if (leap)
				days_per_month[i] = 29;
			else
				days_per_month[i] = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
			days_per_month[i] = 30;
		else
			days_per_month[i] = 31;
	}
	if (day < 1 || day > days_per_month[month - 1])
		return false;
	return true;
}

bool validate_format(const std::string &date) {
	if (date.size() != 10 || date[10] != '\0')
		return false;
	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);
	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	if (dash1 != '-' || dash2 != '-')
		return false;
	for (size_t i = 0; i < date.size(); i++) {
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return false;
	}
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (!validate_day(year, month, day))
		return false;
	return true;
}

/*
bool validate_day(int year, int month, int day) {
// 	std::list<int> days_per_month; // must be an array
// 	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
// 	for (int i = 1; i <= 12; i++) {
// 		if (i == 2) {
// 			if (leap)
// 				days_per_month.push_back(29);
// 			else
// 				days_per_month.push_back(28);
// 		}
// 		else if (i == 4 || i == 6 || i == 9 || i == 11)
// 			days_per_month.push_back(30);
// 		else
// 			days_per_month.push_back(31);
// 	}
// 	std::list<int>::iterator it = days_per_month.begin();
// 	std::advance(it, month - 1);
// 	if (day < 1 || day > *it)
// 		return false;
// 	return true;
// }
*/