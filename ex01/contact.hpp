/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:32:39 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/03 16:38:14 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
//#include <cstdlib>

class Contact
{
	public:
		Contact();
		~Contact();
	private:
		int			index;
		std::string	name;
		std::string	surname;
		std::string	handle;
		std::string	number;
		std::string	secret;
};

#endif
