/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:17:44 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/27 12:21:20 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character();
		Character(std::string const &name);
		Character(Character const &src);
		~Character(); // only parent class destructor needs to be virtual ?
		Character &operator=(Character const &src);
		virtual std::string const &getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		void use(int idx, ICharacter &target);
	private:
		std::string _name;
		AMateria *_inventory[4];
};