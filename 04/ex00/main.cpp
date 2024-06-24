/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:36:08 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 14:36:49 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main() {
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound(); 
    j->makeSound();

    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i2 = new WrongCat();
    meta2->makeSound();
    i2->makeSound();

    delete meta;
    delete j;
    delete i;
    delete meta2;
    delete i2;

    return (0);
}