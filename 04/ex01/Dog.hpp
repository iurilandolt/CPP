/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:18:55 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 16:47:01 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
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