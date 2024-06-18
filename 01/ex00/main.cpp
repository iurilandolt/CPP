/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:24:18 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/18 03:39:56 by iurilandolt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
class vs struct.
struct variables are always public.
structs cant have functions only pointers to functions.
private variables and functions cannot be used outside the instance of the object.
class variables and methods are private by default.
class members can be initialized in the class declaration or in the constructor.
structs elements must be initialized after they are declared.
structs have no constructors/destructors.
a constructor is a special kind of method that allows us to define the behavior of the class object when it is created.
a destructor is a special kind of method that allows us to define the behavior of the class object when it is destroyed.

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
