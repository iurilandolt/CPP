/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:55:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/28 11:37:02 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &src);
		MateriaSource &operator=(MateriaSource const &src);

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);

	private:
		AMateria *memory[4];
};

#endif