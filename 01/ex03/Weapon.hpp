/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:27:29 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:27:31 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType() const;
		void setType(std::string type);
	private:
		std::string _type;
};

#endif
