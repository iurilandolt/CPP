/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:20 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 17:57:24 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/*
Float numbers have a very large range, but they are not precise, specially when dealing with very small or very large numbers.
Fixed point numbers are a compromise between precision and range. 
They are used when we need to represent numbers with a fixed number of decimal places.

In a 32-bit floating-point number, the number is represented as (-1)^sign * 1.fraction * 2^(exponent-127). 
The fraction part has 23 bits, and the exponent part has 8 bits.

The fraction part determines the precision. Since it has 23 bits, it can represent about 7 decimal digits of precision. However,
as the absolute value of the number gets larger or smaller, some of these digits can be lost, leading to a loss of precision.

The exponent part determines the range. Since it has 8 bits, it can represent numbers from about 1.18e-38 to 3.4e38 in magnitude.
However, the larger the magnitude of the number, the less precision it has.


In a fixed-point number, you decide where the "decimal" point is by choosing how many bits are used for the integer part
and how many for the fractional part. This gives you a fixed range and precision.

For example, if you decide to use 24 bits for the integer part and 8 bits for the fractional part in a 32-bit fixed-point number,
you can represent numbers from -8388608 to 8388607 with a precision of 1/256. 

The trade-off is that while you get a consistent precision,
the range of numbers you can represent is more limited compared to floating-point numbers.
*/

#include <iostream>

class Fixed {
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &src);
        Fixed   &operator=(const Fixed &src);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    private:
        int              _value;
        static const int _fBits; // fractional bits
};

#endif