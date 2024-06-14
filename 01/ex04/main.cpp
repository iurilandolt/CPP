/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:52:07 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/14 13:56:29 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	file_emtpy(std::ifstream &filename) {
	return (filename.peek() == std::ifstream::traits_type::eof() ? 1 : 0);
}

void ft_sed(std::string &content, const std::string &target, const std::string &value) {
	size_t pos;

	pos = content.find(target);
	while (pos != std::string::npos) {
		content.erase(pos, target.length());
		content.insert(pos, value);
		pos = content.find(target, pos + value.length());
	}
}

int	main(int argc, char **argv) {
	if (argc != 4)
		return (std::cerr << "[filename] [old string] [new string]" << std::endl, 1);
	std::string content;
	std::ifstream infile(argv[1]);
	if (!infile.is_open() || !infile.good() || file_emtpy(infile))
		return (std::cerr << "Error: could not open file" << std::endl, 1);

	std::string name(argv[1]);
	std::ofstream outfile((name + ".replace"));
	if (!outfile.is_open())
		return (std::cerr << "Error: could not create file" << std::endl, 1);
	while (std::getline(infile, content)) {
		ft_sed(content, argv[2], argv[3]);
		outfile << content;
	}
	outfile << std::endl;
	infile.close();
	outfile.close();
	return (0);
}
