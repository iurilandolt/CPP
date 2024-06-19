/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:20 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:47:39 by rlandolt         ###   ########.fr       */
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
        Fixed   &operator=(const Fixed &src);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    private:
        int              _value;
        static const int _fBits; // fractional bits
};

#endif