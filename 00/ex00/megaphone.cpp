/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:04:31 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/03 16:14:10 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				std::cout << (char)toupper(argv[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
