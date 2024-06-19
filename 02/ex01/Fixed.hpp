/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:52 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 18:04:06 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &src);
        ~Fixed();
        Fixed   &operator=(const Fixed &src);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;
    private:
        int              _value;
        static const int _fBits;
};

// when overloading the << (insertion) operator, the function must be a friend of the class
// to have access to the private members of the class even though the function is not a member of the class
//this overload also returns a reference to the ostream object to allow chaining of the << operator
std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif