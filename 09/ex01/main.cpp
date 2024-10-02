/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:19:14 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/25 16:51:34 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}