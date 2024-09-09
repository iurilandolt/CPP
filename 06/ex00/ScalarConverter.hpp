/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:35 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/09 12:13:23 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:
		void static convert(std::string const & str);
	private:
		ScalarConverter();
		ScalarConverter(std::string const & str);
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & rhs);

		char static getChar(std::string const & str);
		int getInt(std::string const & str);
		float getFloat(std::string const & str);
		double getDouble(std::string const & str);
};

#endif