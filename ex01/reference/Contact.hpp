/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:37:56 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/09 17:29:49 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "utils.hpp"

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickame;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact(void);
		~Contact(void);
		std::string	getPhoneNumber(void);
		void	createContact(void);
		std::string	formatString(std::string str);
		void	bookFormat(int index);
		void	displayContact(void);
};

#endif