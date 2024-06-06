/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:39 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/06 14:16:08 by rlandolt         ###   ########.fr       */
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
		void	displayDetail();
		void	updateEntry(int &index);
		Contact();
		~Contact();
	private:
		void	clipInput(std::string &input);
		std::string setValue(std::string field);
		std::string setNumber();
		std::string	setNote();
		std::string	name;
		std::string	surname;
		std::string	handle;
		std::string	number;
		std::string	secret;
};

#endif
