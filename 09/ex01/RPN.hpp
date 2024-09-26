/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:19:58 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/26 12:52:41 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN {
	public:
		RPN(std::string const & str);
		RPN(RPN const & src);
		~RPN();
		RPN & operator=(RPN const & rhs);
	private:
		RPN();
		std::stack<int> _digits;
};

#endif