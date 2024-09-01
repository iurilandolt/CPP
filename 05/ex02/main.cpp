/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:53:16 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/01 14:50:35 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	AForm *f1;
	try {
		Bureaucrat b1("Bureaucrat1", 2);
		f1 = new ShrubberyCreationForm();
		std::cout << b1 << std::endl;
		std::cout << *f1 << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}