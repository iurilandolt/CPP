/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:25:06 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 17:08:06 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "---------------------" << std::endl;
    std::cout << "Deep Copying" << std::endl;
    
    Dog originalDog;
    Cat originalCat;
    originalDog.getBrain()->setIdea(0, "Bark at the mailman");
    originalCat.getBrain()->setIdea(0, "Chase the red dot");
    std::cout << std::endl;
    Dog *dogCopy = new Dog(originalDog);
    Cat *catCopy = new Cat(originalCat);
    std::cout << dogCopy->getBrain()->getIdea(0) << std::endl;
    std::cout << catCopy->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    delete dogCopy;
    delete catCopy;
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Array of animals" << std::endl;
    std::cout << std::endl;
    Animal *animals[6];
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << std::endl;
    for (int i = 0; i < 6; i++) {
        //delete animals[i];
        animals[i]->~Animal();
    }
    return (0);
}