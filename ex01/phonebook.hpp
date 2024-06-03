/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:48:28 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/03 20:49:42 by rlandolt         ###   ########.fr       */
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
		// SEARCH
		void	displayEntries();
		// DISPLAY
		void 	displayInfo();
	private:
		Contact	entry[SIZE];
};

#endif
