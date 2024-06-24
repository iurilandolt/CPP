/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:18:55 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 12:33:23 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        ~Dog();
        Dog(std::string type);
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        void makeSound() const;
};

#endif