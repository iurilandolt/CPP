/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:24:18 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/14 12:34:40 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
Elaborate on:
what is a class?
what is the difference between an object and a struct?
*/

int	main(void) {
	Zombie reginald("Reginald");
	Zombie *antoine;

	reginald.announce();
	antoine = newZombie("Antoine");
	antoine->announce();
	delete antoine;
	randomChump("Gerald");
	return (0);
}
