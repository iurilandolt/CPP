/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:36:08 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 11:02:05 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

/* in the previous module we learned about henritance and overriding functions with the virtual keyword
in this module we will learn about polymorphism, polymoirphism allows us to use a pointer or a referece from a 
base class object and access the derived class object's functions and variables.
in tthe case bellow we have a pointer to an Animal object, but we can assign it to a Dog or Cat object 
and use that animal pointer to call member functions from the derived class objects.
*/

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