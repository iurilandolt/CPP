/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:38:06 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/09 17:29:45 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"
# include "utils.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int	index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	commandList(void);
		void	displayPhoneBook(void);
		void	searchContact(void);
};

#endif