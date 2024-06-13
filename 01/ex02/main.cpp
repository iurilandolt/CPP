/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:12:01 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/13 17:58:00 by rlandolt         ###   ########.fr       */
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
