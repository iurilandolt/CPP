/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:34:26 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/05 14:47:06 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


int	main() {
	std::string	input;
	PhoneBook	list;

	input = "";
	while (input.compare("EXIT")) {
		list.displayInfo();
		std::cout << "> ";
		std::getline(std::cin,input);
		if (std::cin.eof()) {
			std::cout << std::endl;
	 		return (1);
		}
		if (!input.compare("ADD"))
			list.addEntry();
		else if (!input.compare("SEARCH")) {
			list.displayEntries();
			list.searchEntry();
		}
		else if (input.compare("EXIT"))
			list.displayInfo();
	}
	return (0);
}
