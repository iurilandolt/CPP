/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:05:44 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 14:56:26 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal {
    protected:  
        std::string _type;
        AAnimal();
    public:
        virtual ~AAnimal();
        AAnimal(const std::string type);
        AAnimal(const AAnimal &src);
        AAnimal &operator=(const AAnimal &src);
        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif