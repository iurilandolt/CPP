/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:59 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 22:47:39 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    std::cout << "Fixed tests" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "Arithmetic tests" << std::endl;
    Fixed c(3.5f);
    Fixed d(2.5f);
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;

    std::cout << "Comparison tests" << std::endl;
    std::cout << "c > d: " << ((c > d) ? "true" : "false") << std::endl;
    std::cout << "c < d: " << ((c < d) ? "true" : "false") << std::endl;
    std::cout << "c == d: " << ((c == d) ? "true" : "false") << std::endl;
    std::cout << "c != d: " << ((c != d) ? "true" : "false") << std::endl;

    std::cout << "Pre-increment and post-increment: 0.0039" << std::endl;
    Fixed e(0);
    std::cout << "e: " << e << std::endl;
    std::cout << "e++: " << e++ << std::endl;
    e.setRawBits(0);
    std::cout << "++e: " << ++e << std::endl;
    std::cout << "e--: " << e-- << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "--e: " << --e << std::endl;

    std::cout << "Static min()/max() tests" << std::endl;
    Fixed f(1.5f);
    Fixed g(2.5f); 
    std::cout << "min(" << f << " : " << g << " = " << Fixed::min(f, g) << ")" << std::endl;
    std::cout << "max(" << f << " : " << g << " = " << Fixed::max(f, g) << ")" << std::endl;
    const Fixed h(3.5f);
    const Fixed i(4.5f);
    std::cout << "min(" << h << " : " << i << " = " << Fixed::min(h, i) << ")" << std::endl;
    std::cout << "max(" << h << " : " << i << " = " << Fixed::max(h, i) << ")" << std::endl;
    return 0;
}