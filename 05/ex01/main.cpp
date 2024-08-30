/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:07:41 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/30 14:34:54 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	try {
		
		Bureaucrat b1("Bob", 2);
		Form f1("Form1", 1, 1);
		//f1.beSigned(b1);
		


	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}