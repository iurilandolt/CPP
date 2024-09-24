/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:40:54 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/24 14:52:16 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _database("data.csv") {}

BitcoinExchange::BitcoinExchange(const std::string &filename) : 
	_database("data.csv"),  _infile(filename.c_str()), _infile_name(filename) {
		
	if (!_infile.is_open() || !_infile.good() || _infile.bad() || _infile.fail())
		throw std::runtime_error("BitcoinExchange: could not open input file");
	if (!_database.is_open() || !_database.good() || _database.bad() || _database.fail())
		throw std::runtime_error("BitcoinExchange: could not open database file");
	_parseDB();
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
		if (_database.is_open())
			_database.close();
		_database.open("data.csv");
		if (_infile.is_open())
			_infile.close();
		_infile.open(_infile_name.c_str());
	}
	return *this;
}

bool validate_day(int year, int month, int day)
{
	std::list<int> days_per_month;
	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	for (int i = 1; i <= 12; i++)
	{
		if (i == 2)
		{
			if (leap)
				days_per_month.push_back(29);
			else
				days_per_month.push_back(28);
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			days_per_month.push_back(30);
		else
			days_per_month.push_back(31);
	}
	std::list<int>::iterator it = days_per_month.begin();
	std::advance(it, month - 1);
	if (day < 1 || day > *it)
		return false;
	return true;
}

bool validate_format(const std::string &date)
{
	if (date.size() != 10 || date[10] != '\0')
		return false;
	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);
	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	if (dash1 != '-' || dash2 != '-')
		return false;
	for (size_t i = 0; i < date.size() ; i++) {
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return false;
		else
			continue;
	}
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (!validate_day(year, month, day))
		return false;
	return true;
}

void BitcoinExchange::_parseDB(void) {
	std::string line;
	//std::getline(_database, line); // we need to skip the header if we are using the else if statement
	while (std::getline(_database, line)) {
		std::istringstream iss(line);
		std::string date;
		double rate;
		if (std::getline(iss, date, ',') && iss >> rate) {
			if (!validate_format(date))
				throw std::runtime_error("BitcoinExchange: invalid date format");
			_exchange[date] = rate;
			std::cout << date << "," << _exchange[date] << std::endl;
		}
		// else if (line.size() > 0)
		// 	throw std::runtime_error("BitcoinExchange: invalid line format");
	}
}