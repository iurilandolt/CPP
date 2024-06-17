/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:52:07 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/18 00:05:54 by iurilandolt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Seditor.hpp"

int main(int argc, char **argv) {
	if (argc != 4)
		return (std::cerr << "[filename] [old string] [new string]" << std::endl, 1);
	std::string filename(argv[1]);
	std::string target(argv[2]);
	std::string value(argv[3]);
	Seditor seditor(filename, target, value);
	return (0);
}