/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:31:55 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/18 13:45:15 by iurilandolt      ###   ########.fr       */
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
        Fixed &operator=(const Fixed &src);
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int              _value;
        static const int _fBits;
};

#endif