/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:48:28 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/05 14:46:49 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <istream>
#include <iomanip>
#include "contact.hpp"

# define SIZE 3

class PhoneBook
{
	public:
		// ADD
		void	addEntry();
		// SEARCH
		void	displayEntries();
		void	searchEntry();
		// DISPLAY
		void 	displayInfo();
		PhoneBook();
		~PhoneBook();
	private:
		Contact	entry[SIZE];

};

#endif
