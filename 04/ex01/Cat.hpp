/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:21:06 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 13:20:54 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    private:
        Brain *brain;
    public:
        Cat();
        virtual ~Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &src);
        void makeSound() const;
        Brain *getBrain() const;
};

#endif