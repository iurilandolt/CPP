/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:41:03 by rlandolt          #+#    #+#             */
/*   Updated: 2024/10/01 11:02:58 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &src);
	private:
		BitcoinExchange();
		void _validateFiles(void);
		void _parseDB(void);
		void _parseInput(void);
		void writeData(std::string &date, double value);
		std::map<std::string, double> _exchange;
		std::ifstream _database;
		std::ifstream _infile;
		std::string _infile_name;
};

bool validate_format(const std::string &date);
bool validate_day(int year, int month, int day);

#endif