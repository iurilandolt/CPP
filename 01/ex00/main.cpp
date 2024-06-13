/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:24:18 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/13 17:08:29 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie reginald("Reginald");
	Zombie *antoine;

	antoine = newZombie("Antoine");
	antoine->announce();
	delete antoine;
	randomChump("Gerald");
	return (0);
}
