/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:52 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 18:37:13 by rlandolt         ###   ########.fr       */
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
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        
        Fixed   &operator=(const Fixed &src);

        bool    operator>(const Fixed &src) const;
        bool    operator<(const Fixed &src) const;
        bool    operator>=(const Fixed &src) const;
        bool    operator<=(const Fixed &src) const;
        bool    operator==(const Fixed &src) const;
        bool    operator!=(const Fixed &src) const;

        Fixed   operator+(const Fixed &src) const;
        Fixed   operator-(const Fixed &src) const;
        Fixed   operator*(const Fixed &src) const;
        Fixed   operator/(const Fixed &src) const;

        Fixed   &operator++(); // prefix
        Fixed   operator++(int); // postfix
        Fixed   &operator--();
        Fixed   operator--(int);

        static Fixed    &min(Fixed &a, Fixed &b);
        static Fixed    &max(Fixed &a, Fixed &b);
        static const Fixed    &min(const Fixed &a, const Fixed &b);
        static const Fixed    &max(const Fixed &a, const Fixed &b);

    private:
        int              _value;
        static const int _fBits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif