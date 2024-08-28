/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:57:00 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/28 11:38:05 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (memory[i])
			delete memory[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	*this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src) {
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (memory[i])
				delete memory[i];
			memory[i] = src.memory[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++)
	{
		if (!memory[i])
		{
			memory[i] = m; // should be a clone?
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (memory[i] && memory[i]->getType() == type)
			return (memory[i]->clone());
	}
	return (NULL);
}