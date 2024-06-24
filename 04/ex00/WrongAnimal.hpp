/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:18:35 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 14:23:41 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
    protected:  
        std::string _type;
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal &operator=(const WrongAnimal &src);
        std::string getType() const;
        void makeSound() const;
};

#endif