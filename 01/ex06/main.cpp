/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:26:36 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/16 00:29:23 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(int argc, char **argv) {
	Harl		harl;

	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cout << "Usage: ./harl [debug, info, warning, error]" << std::endl;
	return (0);
}
