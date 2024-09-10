/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:44:40 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/10 18:20:37 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data data;
	data.str = "Hello";
	data.nbr = 42;

	std::cout << "Data: " << data.str << " | " << data.nbr << std::endl;
	std::cout << "Data address: " << &data << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	
	std::cout << "Serialized: " << serialized << std::endl;
	std::cout << "Serialized address: " << &serialized << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized->str << " | " << deserialized->nbr << std::endl;
	std::cout << "Deserialized address: " << deserialized << std::endl;

	return 0;
}