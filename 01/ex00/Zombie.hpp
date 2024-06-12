/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:25:23 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/12 15:11:07 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <new>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce();
	private:
		std::string _name;
	protected:
		Zombie	*newZombie(std::string name);
		void	randomChump(std::string name);
};

#endif
