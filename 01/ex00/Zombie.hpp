/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:25:23 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/17 15:17:02 by iurilandolt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce();
	private:
		std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
