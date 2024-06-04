/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:34:26 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/05 00:18:06 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


int	main() {
	std::string	data;
	PhoneBook	list;

	data = "";
	while (data.compare("EXIT")) {
		list.displayInfo();
		std::cout << "> ";
		std::getline(std::cin,data);
		if (std::cin.eof()) {
			std::cout << std::endl;
	 		return (1);
		}
		if (!data.compare("ADD"))
			list.addEntry();
		else if (!data.compare("SEARCH"))
			list.displayEntries();
		else if (data.compare("EXIT"))
			list.displayInfo();
	}
	return (0);
}
