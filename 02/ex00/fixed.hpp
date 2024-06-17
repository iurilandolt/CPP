/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:31:55 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/17 13:21:30 by iurilandolt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &src);
        Fixed & operator=(const Fixed &src);
    private:
        int              _value;
        static const int _fBits;
};

#endif