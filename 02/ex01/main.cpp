/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:29:59 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 16:36:18 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
The `Fixed` class is designed to handle fixed-point numbers. 
Fixed-point representation is a method of storing numbers in binary format where a certain number of bits are reserved for the integer part 
(the part before the decimal point) and a certain number of bits are reserved for the fractional part (the part after the decimal point).
In binary, the position of the binary point determines the maximum value and the precision (smallest representable increment) of the numbers that can be represented. 
The more bits allocated to the integer part, the larger the numbers that can be represented, but at the cost of precision. 
Conversely, the more bits allocated to the fractional part, the smaller the increment and hence the higher the precision, but at the cost of maximum representable value.
In the `Fixed` class, 8 bits are used for the fractional part, as indicated by the static member `_fBits`. 
This means that the precision of the fractional part is limited to 1/256 (approximately 0.0039).
In the `main` function, several `Fixed` objects are created to demonstrate their behavior:
1. `Fixed a;` - This calls the default constructor, which sets `_value` to 0.
2. `Fixed const b(10);` - This calls the int constructor, which converts the integer 10 to fixed-point representation by shifting it left by `_fBits` bits.
3. `Fixed const c(42.42f);` - This calls the float constructor, which converts the float 42.42 to fixed-point representation by multiplying it by `2^_fBits` and rounding to the nearest integer.
4. `Fixed const d(b);` - This calls the copy constructor, which copies the `_value` from `b` to `d`.
5. `a = Fixed(1234.4321f);` - This creates a temporary `Fixed` object with the value 1234.4321, then calls the assignment operator to copy its `_value` to `a`.
The `std::cout` statements then print the `Fixed` objects as floats and as integers. When printed as floats, the `toFloat` member function is called, which converts the fixed-point `_value` back to a float by dividing it by `2^_fBits`. 
When printed as integers, the `toInt` member function is called, which converts the fixed-point `_value` back to an integer by shifting it right by `_fBits` bits.
The output of the program shows the messages printed by the constructors, assignment operator, and `getRawBits` function, followed by the `Fixed` objects printed as floats and as integers. 
The `Fixed` objects are destructed at the end of the `main` function, which calls their destructors.
*/

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}