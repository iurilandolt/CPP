/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:25:23 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/13 17:03:35 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <new>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void	announce();
		void	setName(std::string name, int i);
	private:
		std::string	itoa(int i);
		std::string _name;
};

Zombie	*zombieHorde(int i, std::string name);

#endif
