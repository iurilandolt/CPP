/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:26:36 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/14 20:08:15 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"




int	main() {
	Harl		harl;
	std::string value;

	value.clear();
	while (value.empty() || value.compare("exit")) {
		std::cout << "Type value for broadcast: 'debug', 'info', 'warning', 'error'" << std::endl;
		std::cout << "Type 'exit' to close the program" << std::endl;
		std::cout << ">";
		std::getline(std::cin, value);
		if (std::cin.eof()) {
			std::cout << std::endl;
	 		return (1);
		}
		harl.complain(value);
	}
	return (0);
}
