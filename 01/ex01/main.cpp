/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:01:56 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/13 17:07:57 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*horde = zombieHorde(5, "Zombie");

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << " ";
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
