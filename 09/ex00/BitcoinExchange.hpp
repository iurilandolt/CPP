/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:41:03 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/24 14:20:23 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <map>
#include <list>

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &src);
	private:
		BitcoinExchange();
		void _parseDB(void);
		std::map<std::string, double> _exchange;
		std::ifstream _database;
		std::ifstream _infile;
		std::string _infile_name;
		//std::ofstream _outfile;
};

bool validate_format(const std::string &date);
bool validate_day(int year, int month, int day);