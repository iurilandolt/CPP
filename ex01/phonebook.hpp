/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:48:28 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/04 12:31:58 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

# define SIZE 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		// ADD
		void	addEntry();
		// SEARCH
		void	displayEntries();
		// DISPLAY
		void 	displayInfo();
	private:
		int findSlot();
		Contact	entry[SIZE];
};

#endif
