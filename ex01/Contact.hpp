/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:39 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/11 20:40:17 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <istream>
#include <iomanip>

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
		int	isAlphaNumeric(std::string input);
		int	isInvalid(std::string input);
		void	trimInput(std::string &input);
		void	trimNumber(std::string &input);
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
