/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:27:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:27:43 by rlandolt         ###   ########.fr       */
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