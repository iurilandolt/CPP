/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:06:14 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/18 11:11:36 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>

template <typename T>
class MutantStack  {
	public:
		MutantStack();
		MutantStack(MutantStack const &src);
		~MutantStack();
		MutantStack &operator=(MutantStack const &src);
	private:
		
};

#include "MutantStack.tpp"

#endif