/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:18:55 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 11:46:03 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal {
    private:
        Brain *brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        void makeSound() const;
        Brain *getBrain() const;
};

#endif