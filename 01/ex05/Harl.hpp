/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:18:17 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/14 20:09:47 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>


class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);
	private:
		void debug();
		void info();
		void warning();
		void error();
		typedef void (Harl::*fptr)(void);
		void trimInput(std::string &input);
};

#endif
