/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:05:44 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 11:04:47 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:  
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const std::string type);
        Animal(const Animal &src);
        Animal &operator=(const Animal &src);
        std::string getType() const;
        virtual void makeSound() const;
};

#endif