/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:35:15 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/16 12:30:23 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string getInput(const std::string prompt) {
	std::string input = "";
	bool valid = false;

	while (!valid)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::exit(0);
		}
		if (std::cin.good() && !input.empty() && !isAllWhitespaces(input))
			valid = true;
		else
		{
			std::cin.clear();
			std::cout << "\033[91mInvalid input, try again.\033[39m" << std::endl;
		}
	}
	return (input);
}

bool	isAllWhitespaces(const std::string str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!std::isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	isValidPhoneNumber(const std::string &number)
{
	size_t i;

	i = 0;
	if (number[0] == '+')
		i = 1;
	while (number[i] && i < 18)
	{
		if (!std::isdigit(number[i]))
			return (false);
		i++;
	}
	if (i > 15 || i < 8)
		return (false);
	return (true);
}