/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:39:37 by rlandolt          #+#    #+#             */
/*   Updated: 2024/10/02 10:47:47 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " 5 4 3 2 1" << std::endl;
		return 1;
	}
	try {
		std::vector<std::string> args(argv + 1, argv + argc);
		PmergeMe p(args);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}