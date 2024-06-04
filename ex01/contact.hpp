/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:39 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/04 20:53:17 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <istream>
#include <iomanip>
//#include <string>

class Contact
{
	public:
		int		index;
		void	displayEntry();
		void	updateEntry();
		//void	setSurName(std::string surname);
		//void	sethandle(std::string handle);
		//void	setSecret(std::string secret);
		Contact();
		~Contact();
	private:
		std::string setValue(std::string field);
		std::string	name;
		std::string	surname;
		std::string	handle;
		std::string	number;
		std::string	secret;
};

#endif
