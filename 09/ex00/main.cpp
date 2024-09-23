/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:40:17 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/23 20:34:43 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange exchange(argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}