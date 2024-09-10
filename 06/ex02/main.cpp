/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:38:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/10 19:17:04 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	std::srand(std::time(NULL));
	int rdm = rand() % 4;
	switch (rdm) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base *p) {
	std::cout << "Pointer: ";
	if (!p)
		std::cout << "NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &r) {
	Base obj;
	std::cout << "Reference: ";
	try {
		obj = dynamic_cast<A&>(r);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		obj = dynamic_cast<B&>(r);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		obj = dynamic_cast<C&>(r);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &e) {}
	std::cout << "NULL" << std::endl;
}

int main() {
	Base *obj = generate();
	identify(obj);
	identify(*obj);
	delete obj;
	return 0;
}