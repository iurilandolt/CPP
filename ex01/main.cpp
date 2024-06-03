/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:34:26 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/03 16:23:32 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main() {

	std::string	data;
	PhoneBook	list;

	data = "";
	while (data.compare("EXIT")) {
		std::cout << "> ";
		std::cin >> data;
		if (std::cin.eof()) {
			std::cout << std::endl;
	 		return (1);
		}
		if (!data.compare("ADD"))
			std::cout << "ADD function called" << std::endl;
		else if (!data.compare("SEARCH"))
			std::cout << "SEARCH function called" << std::endl;
		else
			list.Display();
	}
	return (0);
}
