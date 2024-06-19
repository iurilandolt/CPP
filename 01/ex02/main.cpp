/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:27:03 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:27:06 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string str;
	std::string *ptr;

	str = "HI THIS IS BRAIN";
	ptr = &str;

	std::string &ref = str;

	std::cout << &str << ": " << str << std::endl;
	std::cout << ptr << ": " << *ptr << std::endl;
	std::cout << &ref << ": " << ref << std::endl;
	return (0);
}

/*
Pointers:
A pointer is a variable that holds a memory address of another variable.
A pointer needs to be dereferenced with * to access the memory location it points to.
Pointers can be reassigned to point to different variables.
Pointers can be null.
Pointers can point to the middle of an array. (be indexed)
Pointers can be incremented/decremented.

References:
A reference is an alias, or an alternative name for an already existing variable.
A reference always refers to the object it was initialized with.
References cannot be null.
A referece cannot refer to another reference.
References must be initialized when they are created.
References do not need dereferencing.

In this code, str is a std::string object, ptr is a pointer to str, and ref is a reference to str. 
When you print &str and &ref, you get the same memory address because ref is an alias for str. 
When you print ptr, you also get the same memory address because ptr points to str. 
When you print *ptr and ref, you get the same string because both are ways to access the str object.
*/