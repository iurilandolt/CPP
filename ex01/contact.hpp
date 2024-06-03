/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:39 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/03 20:48:25 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	public:
		int		index;
		void	displayEntry(int i);
		Contact();
		~Contact();
	private:
		std::string	name;
		std::string	surname;
		std::string	handle;
		std::string	number;
		std::string	secret;
};

#endif
