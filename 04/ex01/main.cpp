/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:25:06 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 19:16:58 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Dog originalDog;
    Cat originalCat;
    originalDog.getBrain()->setIdea(0, "Bark at the mailman");
    originalCat.getBrain()->setIdea(0, "Chase the red dot");

    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Deep Copying" << std::endl;
    std::cout << "---------------------" << std::endl;
    
    std::cout << std::endl;
    Dog *dogCopy = new Dog(originalDog);
    Cat *catCopy = new Cat(originalCat);

    std::cout << std::endl;
    std::cout << "Dog: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog copy: " << dogCopy->getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat copy: " << catCopy->getBrain()->getIdea(0) << std::endl;
    
    std::cout << std::endl;
    std::cout << "Original Dog Brain address: " << originalDog.getBrain() << std::endl;
    std::cout << "Original Cat Brain address: " << originalCat.getBrain() << std::endl;
    std::cout << "Copied Dog Brain address: " << dogCopy->getBrain() << std::endl;
    std::cout << "Copied Cat Brain address: " << catCopy->getBrain() << std::endl;
    
    std::cout << std::endl;
    std::cout << "Original Dog address: " << &originalDog << std::endl;
    std::cout << "Original Cat address: " << &originalCat << std::endl;
    std::cout << "Copied Dog address: " << dogCopy << std::endl;
    std::cout << "Copied Cat address: " << catCopy << std::endl;

    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Assignation operator" << std::endl;
    std::cout << "---------------------" << std::endl;
    
    std::cout << std::endl;
    Dog testDog;
    testDog = originalDog;
    std::cout << std::endl;
    std::cout << "Test Dog: " << testDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Test Dog Brain address: " << testDog.getBrain() << std::endl;
    std::cout << "Test Dog address: " << &testDog << std::endl;
    
    std::cout << std::endl;
    delete dogCopy;
    delete catCopy;

    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Array of animals" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    Animal *animals[6];
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog(originalDog);
        else
            animals[i] = new Cat(originalCat);
    }
    std::cout << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << animals[i]->getType() << " : " << &animals[i] << std::endl;
        delete animals[i];
    }
    std::cout << std::endl;
    return (0);
}