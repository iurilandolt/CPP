/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:41:03 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/23 20:31:43 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string &filename);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &src);
	private:
		BitcoinExchange();
		//std::map<std::string, double> _exchange;
		std::ifstream _database;
		std::ifstream _infile;
		//std::ofstream _outfile;
};