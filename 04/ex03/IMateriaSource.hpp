/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:51:46 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/28 11:35:01 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "Ice.hpp"
#include "Cure.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria *m) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif