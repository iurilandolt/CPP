/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:09:35 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/09 23:03:32 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <climits>
//#include <cfloat>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
	public:
		void static convert(std::string const & str);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & src);

		static std::string sanitize(std::string const & src);
		static bool checkPseudoLiteral(std::string const & str);
		static void parse(std::string const & str);
		//static double ft_stod(std::string const & str);
		static char getChar(double raw);
		static int getInt(double raw);
		static float getFloat(double raw);
		static double getDouble(double raw);
};

#endif